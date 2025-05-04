#include "Recommender.h"

float user1Rating;
float user2Rating;
double ratingcalculation;
float rating1;
double totalSumSquaredError = 0.0; // Total squared error
int totalPredictionCount = 0;
int deneme = 0;

void Recommender::addEducatedRating(int userID, int movieID, float rating) {
    educated_userMovieMap[userID].emplace_back(movieID, rating);
    educated_movieUserMap[movieID].emplace_back(userID, rating);
}
void Recommender::addTestRating(int userID, int movieID, float rating) {
    test_userMovieMap[userID].emplace_back(movieID, rating);
}

void Recommender::predictAllRatings() {
    const int MAX_THREADS = 4; // Adjust number of threads as needed
    queue<pair<int, pair<int, int>>> taskQueue; // Queue to store test input tasks (index, userId, movieId)
    mutex queueMutex; // Mutex for task queue
    condition_variable cv; // Condition variable to synchronize threads
    bool done = false; // Flag to signal threads when tasks are done

    // Populate the task queue with test input
    for (const auto& user : test_userMovieMap) {
        for (const auto& movie : user.second) {
            taskQueue.push({ user.first, {movie.first, movie.second} }); // userId, (movieId, actualRating)
        }
    }

    // Worker function for threads
    auto worker = [&]() {
        while (true) {
            pair<int, pair<int, int>> task;

            // Retrieve a task from the queue
            {
                unique_lock<mutex> lock(queueMutex);
                cv.wait(lock, [&]() { return !taskQueue.empty() || done; });

                if (done && taskQueue.empty()) {
                    break; // Exit the loop when all tasks are completed
                }

                task = taskQueue.front();
                taskQueue.pop();
            }

            int userId = task.first;                 // User ID
            int movieId = task.second.first;         // Movie ID
            float actualRating = task.second.second; // Actual rating from test data

            // Predict rating
            double predictedRating = predictRatingHybrid(userId, movieId, actualRating);

            // Update RMSE with the actual rating
            updateRMSE(actualRating, predictedRating);
        }
        };

    // Create worker threads
    vector<thread> workers;
    for (int i = 0; i < MAX_THREADS; ++i) {
        workers.emplace_back(worker);
    }

    // Notify all threads to start processing
    {
        unique_lock<mutex> lock(queueMutex);
        done = true;
    }
    cv.notify_all();

    // Wait for all threads to finish
    for (auto& worker : workers) {
        worker.join();
    }
}

double Recommender::PearsonUBCF(int User1, int User2) {
    const auto& movies1 = educated_userMovieMap[User1];
    const auto& movies2 = educated_userMovieMap[User2];

    unordered_map<int, float> user2Ratings;
    for (const auto& movie : movies2) {
        user2Ratings[movie.first] = movie.second;
    }

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
    int n = 0;

    for (const auto& movie : movies1) {
        int movieID = movie.first;
        float rating1 = movie.second;

        if (user2Ratings.count(movieID)) {
            float rating2 = user2Ratings[movieID];
            sumX += rating1;
            sumY += rating2;
            sumXY += rating1 * rating2;
            sumX2 += rating1 * rating1;
            sumY2 += rating2 * rating2;
            n++;
        }
    }

    if (n == 0) return 0.0;

    double denominator = sqrt(sumX2) * sqrt(sumY2);
    return denominator == 0 ? 0.0 : (sumXY / denominator);
}

float Recommender::predictRatingUBCF(int targetUser, int targetMovie) {
    vector<pair<double, int>> similarities;

    for (const auto& user : educated_userMovieMap) {
        if (user.first == targetUser) continue;
        double similarity = PearsonUBCF(targetUser, user.first);
        if (similarity > 0) {
            similarities.emplace_back(similarity, user.first);
        }
    }

    sort(similarities.rbegin(), similarities.rend());

    int k = min(5, static_cast<int>(similarities.size()));

    double numerator = 0.0, denominator = 0.0;
    int count = 0;

    for (const auto& simPair : similarities) {
        if (count >= k) break;
        int similarUser = simPair.second;

        for (const auto& movie : educated_userMovieMap[similarUser]) {
            if (movie.first == targetMovie) {
                numerator += simPair.first * movie.second;
                denominator += simPair.first;
                count++;
                break;
            }
        }
    }

    return denominator == 0.0 ? 0.0 : (numerator / denominator);
}

// Item similarity
double Recommender::itemSimilarity(int movie1, int movie2) {
    double dotProduct = 0.0, norm1 = 0.0, norm2 = 0.0;

    for (const auto& user : educated_movieUserMap[movie1]) {
        int userID = user.first;
        float rating1 = user.second;

        for (const auto& movie : educated_userMovieMap[userID]) {
            if (movie.first == movie2) {
                float rating2 = movie.second;
                dotProduct += rating1 * rating2;
                norm1 += rating1 * rating1;
                norm2 += rating2 * rating2;
            }
        }
    }

    double denominator = sqrt(norm1) * sqrt(norm2);
    return denominator == 0 ? 0.0 : (dotProduct / denominator);
}

// Predict rating using IBCF
float Recommender::predictRatingIBCF(int targetUser, int targetMovie) {
    const auto& userMovies = educated_userMovieMap[targetUser];

    double numerator = 0.0, denominator = 0.0;

    for (const auto& movie : userMovies) {
        double similarity = itemSimilarity(targetMovie, movie.first);
        numerator += similarity * movie.second;
        denominator += similarity;
    }

    return denominator == 0.0 ? 0.0 : (numerator / denominator);
}
double Recommender::predictRatingHybrid(int targetUser, int targetMovie, float actual, float alpha) {
    float ubcfRating = predictRatingUBCF(targetUser, targetMovie);
    float ibcfRating = predictRatingIBCF(targetUser, targetMovie);

    // Combine predictions with fallback to global average
    double predictedRating = alpha * ubcfRating + (1.0 - alpha) * ibcfRating;

    // Output predicted rating in required format
    return predictedRating;
}

void Recommender::updateRMSE(float actual, float predicted) {
    // Calculate squared error for this prediction
    double squaredError = (actual - predicted) * (actual - predicted);
    totalSumSquaredError += squaredError;

    // Increment prediction count
    totalPredictionCount++;
    cout << "tamamlandi: " << totalPredictionCount << endl;
    // Calculate and display instant RMSE
    double instantRMSE = sqrt(totalSumSquaredError / totalPredictionCount);
    //cout << "Actual: " << actual << ", Predicted: " << predicted
      //  << ", Instant RMSE: " << instantRMSE << endl;
}

double Recommender::getAverageRMSE() {
    if (totalPredictionCount == 0) {
        cerr << "No predictions made. Cannot calculate average RMSE." << endl;
        return 0.0;
    }

    // Calculate and return average RMSE
    return sqrt(totalSumSquaredError / totalPredictionCount);
}