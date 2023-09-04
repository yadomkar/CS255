// Created by Omkar Yadav on 9/3/23.
//
// Time Complexity: O(lgn)
// Space Complexity: O(1)
//

#include<vector>
#include<iostream>

using namespace std;

class Question2 {
public:
    static int whereIsTheZero(vector<int>& a, vector<int>& b) {
        int start = 0, end = (int) b.size();

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(b[mid] == 0) return mid + 1;
            else if(b[mid] == a[mid]) start = mid + 1;
            else end = mid - 1;
        }

        return (int) b.size();
    }
};

int main() {
    vector<int> a = {1, 3, 4, 6, 7, 8, 9, 20};
    vector<int> b = {1, 3, 0, 4, 6, 7, 8, 9, 20};

    int zeroIndex = Question2::whereIsTheZero(a, b);

    cout << zeroIndex << endl;
    return 0;
}