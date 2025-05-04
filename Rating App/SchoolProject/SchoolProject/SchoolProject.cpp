#include "Recommender.h"

using namespace std;

string str;
string number;
int userId;
int movieId;
float rating;

string removeQuotes() {
    if (str.size() >= 2 && str.front() == '"' && str.back() == '"') return str.substr(1, str.size() - 2);
    return str;
}

static int stringToInt() { return stoi(number); }
static float stringToFloat() { return stof(str); }

string divideString(string label) {
    if (label == "UserID" || label == "itemID") {
        size_t sizeofstring = str.find(",");
        number = str.substr(0, sizeofstring);
        return str.substr(sizeofstring + 1);
    }
    return "";
}

void processLine() {
    str = removeQuotes();
    str = divideString("UserID");
    userId = stringToInt();
    str = divideString("itemID");
    movieId = stringToInt();
    divideString("Rating");
    rating = stringToFloat();
}

void getData(string filelocation, Recommender& system, bool IsEducatedData) {
    fstream getData;
    getData.open(filelocation, ios::in | ios::binary);

    if (!getData.is_open()) cout << "File does not exist";
    else {
        getline(getData, str);
        while (getline(getData, str)) {
            processLine();
            if (IsEducatedData) system.addEducatedRating(userId, movieId, rating);
            else system.addTestRating(userId, movieId, rating);
        }
        cout << "Yukleme tamamlandi" << endl;
        getData.close();
    }
}

int main() {
    Recommender system;
    ios::sync_with_stdio(false);
    cin.tie(0);

    string trainData = "train_data.csv"; // Replace with actual train file path
    string testData = "test_data.csv";   // Replace with actual test file path

    // Load training and test data
    getData("C:\\Users\\İlker\\Downloads\\train_dataset.csv", system, false); // Load training data
    getData("C:\\Users\\İlker\\Downloads\\test_dataset.csv", system, true);  // Load test data

    // Calculate global average for fallback
    //system.globalAverage = system.calculateGlobalAverage();

    // Predict all ratings
    system.predictAllRatings();

    // Output the average RMSE
    cout << fixed << setprecision(4) << "Average RMSE: " << system.getAverageRMSE() << endl;

    return 0;
}
