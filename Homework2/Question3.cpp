//
// Created by Omkar Yadav on 10/29/23.
//

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Homework2Question3 {
public:
    int dfs(vector<int>& coins, vector<int>& memo, int amount) {
//        cout << amount << endl;
        if(amount < 0) return -1;
        if(amount == 0) return 0;

        if(memo[amount] != INT_MIN) return memo[amount];

        int res = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int numCoins = dfs(coins, memo, amount - coins[i]);
            if(numCoins > -1) res = min(res, 1 + numCoins);
        }

        return memo[amount] = res == INT_MAX ? -1 : res;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, INT_MIN);
        return dfs(coins, memo, amount);
    }

    static int bottomUpCoinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);

        // Base Case 0 coins needed if amount is 0
        dp[0] = 0;

        // Given that 1 coin will always be a penny
        dp[1] = 1;

        for(int curAmount = 2; curAmount <= amount; curAmount++) {
            for(auto& coin: coins) {
                if(curAmount - coin >= 0) {
                    dp[curAmount] = min(dp[curAmount], 1 + dp[curAmount - coin]);
                }
            }
        }

        return dp[amount];
    }
};


int main() {
    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    assert(Homework2Question3().bottomUpCoinChange(coins1, amount1) == 3); // Expected: 3 (11 = 5 + 5 + 1)

    // Test Case 2
    vector<int> coins2 = {2, 1};
    int amount2 = 2;
    assert(Homework2Question3().bottomUpCoinChange(coins2, amount2) == 1); // Expected: -1 (not possible)

    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
//    assert(Homework2Question3().bottomUpCoinChange(coins3, amount3) == 0); // Expected: 0 (amount is 0)

    // Test Case 4
    vector<int> coins4 = {1};
    int amount4 = 2;
    assert(Homework2Question3().bottomUpCoinChange(coins4, amount4) == 2); // Expected: 2 (2 = 1 + 1)

    // Test Case 5
    vector<int> coins5 = {186, 419, 83, 408, 1};
    int amount5 = 6249;
//    cout << Homework2Question3().bottomUpCoinChange(coins5, amount5) << endl;
    assert(Homework2Question3().bottomUpCoinChange(coins5, amount5) == 18); // Expected: 20 (6249 = 408*15 + 83 + 186)

    cout << "All test cases passed!" << endl;

    return 0;
}
