#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double dotProduct(const vector<double>& v1, const vector<double>& v2) {
    return v1[0] * v2[0] + v1[1] * v2[1];
}

double magnitude(const vector<double>& v) {
    return sqrt(v[0] * v[0] + v[1] * v[1]);
}

double cosineSimilarity(const vector<double>& v1, const vector<double>& v2) {
    return dotProduct(v1, v2) / (magnitude(v1) * magnitude(v2));
}

int main() {
    ifstream inputFile("vectors.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    vector<vector<double>> vectors;
    vector<pair<int, int>> pairs;

    double x, y;
    while (inputFile >> x >> y) {
        vectors.push_back({x, y});
    }
    inputFile.close();

    int n = vectors.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pairs.push_back({i, j});
        }
    }

    sort(pairs.begin(), pairs.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
        double cosine1 = cosineSimilarity(vectors[p1.first], vectors[p1.second]);
        double cosine2 = cosineSimilarity(vectors[p2.first], vectors[p2.second]);
        return cosine1 > cosine2;
    });

    cout << "Pairs of vectors ordered by cosine closeness:" << endl;
    for (const auto& pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}
