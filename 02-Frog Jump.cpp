#include <bits/stdc++.h>
using namespace std;
//Recursion_Way
class Solution {
  private:
    int solve(int index, vector<int>& height) {
        // Base case: If we are at the starting stone, cost is 0
        if (index == 0) {
            return 0;
        }
        // Cost from jumping from the previous stone (index - 1)
        int jump_one = solve(index - 1, height) + abs(height[index] - height[index - 1]);

        // Cost from jumping from two stones back (index - 2)
        int jump_two = INT_MAX;
        if (index > 1) {
            jump_two = solve(index - 2, height) + abs(height[index] - height[index - 2]);
        }

        return min(jump_one, jump_two);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // We need to find the minimum energy to reach the last stone (n-1)
        return solve(n - 1, height);
    }
};

int main() {
    Solution sol;
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();
    cout << "Minimum energy (Recursion): " << sol.minimumEnergy(height, n) << endl;
    return 0;
}
//____________________________________________________________________________________________________

//Memoization_Way

int solve(int index, vector<int>& height, vector<int>& dp) {
        // Base case
        if (index == 0) {
            return 0;
        }
        // If the result is already computed, return it
        if (dp[index] != -1) {
            return dp[index];
        }

        int jump_one = solve(index - 1, height, dp) + abs(height[index] - height[index - 1]);
        
        int jump_two = INT_MAX;
        if (index > 1) {
            jump_two = solve(index - 2, height, dp) + abs(height[index] - height[index - 2]);
        }

        // Store the result before returning
        return dp[index] = min(jump_one, jump_two);
}

//____________________________________________________________________________________________________
//Tabulation_Way

int minimumEnergy(vector<int>& height, int n) {
        if (n <= 1) return 0;

        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            int jump_one = dp[i - 1] + abs(height[i] - height[i - 1]);

            int jump_two = INT_MAX;
            if (i > 1) {
                jump_two = dp[i - 2] + abs(height[i] - height[i - 2]);
            }

            dp[i] = min(jump_one, jump_two);
        }

        return dp[n - 1];
}

//____________________________________________________________________________________________________

//Space_Optimization_way

int minimumEnergy(vector<int>& height, int n) {
        if (n <= 1) return 0;
        
        int prev2 = 0; // Cost to reach i-2
        int prev1 = 0; // Cost to reach i-1

        for (int i = 1; i < n; ++i) {
            int jump_one = prev1 + abs(height[i] - height[i - 1]);

            int jump_two = INT_MAX;
            if (i > 1) {
                jump_two = prev2 + abs(height[i] - height[i - 2]);
            }
            
            int current = min(jump_one, jump_two);

            // Update pointers for the next iteration
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
}
