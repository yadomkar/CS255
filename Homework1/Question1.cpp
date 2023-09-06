//
// Created by Omkar Yadav on 9/3/23.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//

#include <vector>
#include <iostream>
using namespace std;

class Question1 {
public:
    static pair<char, char> charactersMedianAndMode(const vector<char>& data) {
        vector<int> freq(52);
        for(char c: data) {
            if(c >= 'a' and c <= 'z') freq[c - 'a']++;
            else if(c >= 'A' and c <= 'Z') freq[c - 'A' + 26]++;
        }
        return {getMedian(freq, (int) data.size()), getMode(freq)};
    }

    static char getMedian(vector<int>& freq, int n) {
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

    static char getMode(vector<int>& freq) {
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
    vector<char> input1 = {'F', 'A', 'D', 'A', 'B', 'A'};
    vector<char> input2 = {'G', 'F', 'R', 'R', 'C'};
    pair<char, char> answer1 = Question1::charactersMedianAndMode(input1);
    pair<char, char> answer2 = Question1::charactersMedianAndMode(input2);

    cout << "Answer 1: " << endl;
    cout << "Median: " << answer1.first << " ";
    cout << "Mode: " << answer1.second << endl;

    cout << "Answer 2: " << endl;
    cout << "Median: " << answer2.first << " ";
    cout << "Mode: " << answer2.second << endl;
    return 0;
}

/*

Output:
Answer 1:
Median: A Mode: A
Answer 2:
Median: G Mode: R

 */

