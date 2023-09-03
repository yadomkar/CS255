// Created by Omkar Yadav on 9/3/23.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//

#include<vector>
#include <iostream>
using namespace std;

class Question1 {
public:
    pair<char, char> charactersMedianAndMode(const vector<char>& data) {
        vector<int> freq(52);
        for(char c: data) {
            if(c >= 'a' and c <= 'z') freq[c - 'a']++;
            else if(c >= 'A' and c <= 'Z') freq[c - 'A' + 26]++;
        }
        return {getMedian(freq, (int) data.size()), getMode(freq)};
    }

    char getMedian(vector<int>& freq, int n) {
        int medianIndex = (n % 2 == 0) ? (n / 2) - 1 : n / 2;
        int cumulativeFreq = 0;
        int median = 0;

        for(int i = 0; i < freq.size(); i++) {
            cumulativeFreq += freq[i];
            if(cumulativeFreq > medianIndex) {
                median = i;
                break;
            }
        }

        return median < 26 ? median + 'a' : median - 26 + 'A';
    }

    char getMode(vector<int>& freq) {
        int modeCount = 0;
        int modeIndex = 0;

        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] > modeCount) {
                modeCount = freq[i];
                modeIndex = i;
            }
        }

        return modeIndex < 26 ? modeIndex + 'a' : modeIndex - 26 + 'A';
    }
};

int main() {
//    vector<char> input = {'F', 'A', 'D', 'A', 'B', 'A'};
    vector<char> input = {'G', 'F', 'R', 'R', 'C'};
    pair<char, char> answer = Question1().charactersMedianAndMode(input);
    cout << "Median: " << answer.first << endl;
    cout << "Mode: " << answer.second << endl;
    return 0;
}

