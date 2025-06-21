#include <bits/stdc++.h>
using namespace std;
// Simple recursive function
int fib_recursive(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    // Recursive relation
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}
int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") using Recursion: "
         << fib_recursive(n) << endl;
    return 0;
}
//-----------------------------------------------------------------------------------
// Memoization function
int fib_memo(int n, vector<int>& dp) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    // If the value is already computed, return it
    if (dp[n] != -1) {
        return dp[n];
    }
    // Otherwise, compute, store, and return the value
    dp[n] = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
    return dp[n];
}
//-----------------------------------------------------------------------------------
// Tabulation function
int fib_tab(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> dp(n + 1);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Build the table iteratively from the bottom up
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//-----------------------------------------------------------------------------------
// Space-optimized function
int fib_space_optimized(int n) {
    if (n <= 1) {
        return n;
    }
    int prev2 = 0; // Represents F(i-2)
    int prev1 = 1; // Represents F(i-1)

    // Iterate from 2 to n
    for (int i = 2; i <= n; ++i) {
        int current = prev1 + prev2;
        // Update variables for the next iteration
        prev2 = prev1;
        prev1 = current;
    }
    return prev1; // prev1 holds the nth Fibonacci number
}
