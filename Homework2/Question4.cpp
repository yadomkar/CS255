//
// Created by Omkar Yadav on 10/28/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

class Homework2Question4 {
public:
    static vector<int> merge2Arrays(vector<int>& arrayA, vector<int>& arrayB) {
        vector<int> mergedArray;

        // Pointers to iterate over the 2 arrays
        int a = 0, b = 0;
        while(a < arrayA.size() and b < arrayB.size()) {
            if(arrayA[a] < arrayB[b]) mergedArray.push_back(arrayA[a++]);
            else mergedArray.push_back(arrayB[b++]);
        }

        while(a < arrayA.size()) mergedArray.push_back(arrayA[a++]);
        while(b < arrayB.size()) mergedArray.push_back(arrayB[b++]);

        return mergedArray;
    }


    static vector<int> mergeKArrays(vector<vector<int>>& kArrays) {
        queue<vector<int>> q;
        for(auto& array: kArrays) q.push(array);

        while(q.size() > 1) {
            vector<int> arrayA = q.front(); q.pop();
            vector<int> arrayB = q.front(); q.pop();

            q.push(merge2Arrays(arrayA, arrayB));
        }

        return q.front();
    }

};

int main() {
    srand(time(0)); // Seed the random number generator

    const int k = 5;  // Number of sorted arrays
    const int n = 10;  // Number of elements in each array

    vector<vector<int>> sorted_vectors;

    for (int i = 0; i < k; ++i) {
        vector<int> vec(n);

        for (int j = 0; j < n; ++j) {
            vec[j] = rand() % 100;  // Random numbers between 0 and 99
        }

        sort(vec.begin(), vec.end());  // Sort the vector
        sorted_vectors.push_back(vec);
    }

    // To demonstrate, print out the k sorted vectors
    for (const auto& vec : sorted_vectors) {
        for (int num : vec) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    vector<int> mergedTest = Homework2Question4::mergeKArrays(sorted_vectors);

    for(auto& num: mergedTest) cout << num << " ";

    return 0;
}
