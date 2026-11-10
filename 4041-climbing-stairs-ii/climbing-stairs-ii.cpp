class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            dp[i] = min({
                dp[i-1] + 1 + costs[i-1],
                i >= 2 ? dp[i-2] + 4 + costs[i-1] : INT_MAX,
                i >= 3 ? dp[i-3] + 9 + costs[i-1] : INT_MAX
            });
        }

        return dp[n];
    }
};