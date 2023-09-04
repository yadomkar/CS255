# Homework 1 Documentation
**Author:** Omkar Yadav

---

## Q1: CHARACTERS MEDIAN AND MODE

Given an array of size **n** that contains only Latin characters, describe an efficient algorithm that finds the median (lower if 'n' is even) and the mode (most frequent element). If there are multiple elements that appear the maximum number of times, output any one of them.

What is the time and space complexity?

**Examples:**
```
Input: array a[] = {F, A, D, A, B, A}  
Output: Mode = A, Median = A

Input: array a[] = {G, F, R, R, C}  
Output: Mode = R, Median = G
```

### Assumption 
Latin characters refer to ASCII characters and exclude UTF-8 special characters.

### Approach
The solution employs a frequency array of size 52, representing uppercase and lowercase characters. The frequency array is used to compute the median and mode in constant time and space.

### Code
<details>
<summary>Snippet</summary>

```cpp
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
```
</details>

### Analysis
**Time Complexity:** $O(n)$
- Where n is the size of the input array. 
- We traverse the input array once to compute frequencies. After this, processing on the frequency array is in constant time due to its fixed size.

**Space Complexity:** $O(1)$
- As the frequency array is of fixed size, we only use constant space.

---

## Q2: WHERE IS THE ZERO?
Alice has a sorted array `A[1, . . . , n]` with distinct positive numbers. Now Bob has another almost
sorted array `B[1, . . . , n + 1]`, which is derived from inserting a zero into A. Help Bob to discover
the index of this zero. Design and analyze an efficient algorithm for him to find the index of the
zero in B. 

Hint: use A and B in your solution.

**Example:**
```
If
A ∶ 1, 3, 4, 6, 7, 8, 9, 20
B ∶ 1, 3, 0, 4, 6, 7, 8, 9, 20.

Your algorithm should return 3 in this case, 
which is the index of the zero in B (starting from 1).
```

### Assumption
Array A only contains positive numbers.

### Approach
- **Brute Force:** Linear search for 0 in array B. 
- **Optimal Approach:** Divide and Conquer (modified binary search) using both arrays.

### Code
<details>
<summary>Snippet</summary>

```cpp
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
```
</details>

### Analysis
**Time Complexity:** $O(\lg n)$
- Where n is the size of the input arrays.
- 

**Space Complexity:** $O(1)$
- As the frequency array is of fixed size, we only use constant space.

---


