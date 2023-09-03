## Question 1: CHARACTERS MEDIAN AND MODE

Given an array of size 'n' that contains only Latin characters, describe an efficient algorithm that finds the median (lower if 'n' is even) and the mode (most frequent element). If there are multiple elements that appear the maximum number of times, output any one of them.

**What is the time and space complexity?**

**Examples:**  
Input: array a[] = {F, A, D, A, B, A}  
Output: Mode = A, Median = A

Input: array a[] = {G, F, R, R, C}  
Output: Mode = R, Median = G

---

**Answer 1:**

**Assumption:** Latin characters are only the ASCII characters, and not UTF-8 special characters.

**Approach:** Make a frequency array of size 52 (26 uppercase and 26 lowercase characters). Find the Median and Mode through this.
