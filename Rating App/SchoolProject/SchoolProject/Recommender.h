#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <future>
#include <queue>
#include <fstream>

using namespace std;

class Recommender {
public:
    unordered_map<int, vector<pair<int, float>>> educated_userMovieMap;
    unordered_map<int, vector<pair<int, float>>> educated_movieUserMap;
    unordered_map<int, vector<pair<int, float>>> test_userMovieMap;
    vector<pair<int, int>> testInputOrder;
    double globalAverage = 0.0;

    void addEducatedRating(int userID, int movieID, float rating);
    void addTestRating(int userID, int movieID, float rating);
    double predictRatingHybrid(int targetUser, int targetMovie, float actual, float alpha = 0.5);
    double PearsonUBCF(int User1, int User2);
    float predictRatingUBCF(int targetUser, int targetMovie);
    double itemSimilarity(int movie1, int movie2);
    float predictRatingIBCF(int targetUser, int targetMovie);
    //double calculateGlobalAverage();
    void predictAllRatings();
    void updateRMSE(float actual, float predicted);
    double getAverageRMSE();
};