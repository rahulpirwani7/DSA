class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);
        int n=cost.size();

        for(int i=0;i<n;i++)
            dp[i]=cost[i];
        

        for(int i=2;i<=cost.size();i++)
            dp[i]+=min(dp[i-1],dp[i-2]);
        
        return dp[n];

    }
};