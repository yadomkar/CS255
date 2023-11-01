//
// Created by Omkar Yadav on 11/1/23.
//

#include <vector>
#include <iostream>

using namespace std;

class Homework2Question2 {
public:
    static int bruteMaximumSubarray(vector<int>& array) {
        int maxSum = INT_MIN;
        for(int start = 0; start < array.size(); start++) {
            int curSum = 0;
            for(int end = start; end < array.size(); end++) {
                curSum += array[end];
                maxSum = max(maxSum, curSum);
            }
        }
        return maxSum;
    }

    int dncMaximumSubarray(vector<int>& array) {
        return divideAndConquer(array, 0, array.size() - 1);
    }

    int divideAndConquer(vector<int>& array, int start, int end) {
        if(start == end) return array[start];

        int mid = start + (end - start) / 2;
        int leftSum = divideAndConquer(array, start, mid);
        int rightSum = divideAndConquer(array, mid + 1, end);
        int crossingSum = getCrossingSum(array, start, mid, end);

        return max(crossingSum, max(leftSum, rightSum));
    }

    static int getCrossingSum(vector<int>& array, int start, int mid, int end) {
        int leftMaxSum= INT_MIN, rightMaxSum = INT_MIN;

        int curSum = 0;
        for(int i = mid; i >= start; i--) {
            curSum += array[i];
            leftMaxSum = max(leftMaxSum, curSum);
        }

        curSum = 0;
        for(int i = mid + 1; i <= end; i++) {
            curSum += array[i];
            rightMaxSum = max(rightMaxSum, curSum);
        }

        return leftMaxSum + rightMaxSum;
    }

    static vector<int> kadanesMaximumSubarray(vector<int>& array) {
        int maxSum = 0, maxTemp = 0;
        int arrive = 0, depart = -1;

        for(int i = 0; i < array.size(); i++) {
            maxTemp += array[i];

            if(maxTemp < 0) {
                maxTemp = 0;
                arrive = i + 1;
            }

            if(maxSum < maxTemp) {
                maxSum = maxTemp;
                depart = i;
            }
        }

        if(maxSum <= 0) depart = -1;

        return {maxSum, arrive, depart};
    }
};

int main() {
    vector<int> array = {-2,1,-3,4,-1,2,1,-5,4}; // Expected: 6
    cout << Homework2Question2::bruteMaximumSubarray(array) << endl;

    cout << Homework2Question2().dncMaximumSubarray(array) << endl;

    vector<int> kadane = Homework2Question2::kadanesMaximumSubarray(array);
    cout << "Max Sum: " << kadane[0] << endl;
    cout << "Arrive Index: " << kadane[1] << endl;
    cout << "Depart Index: " << kadane[2] << endl;

    return 0;
}
