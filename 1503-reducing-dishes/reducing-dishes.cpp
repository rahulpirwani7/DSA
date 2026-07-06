class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // try
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,0));

        for(int i=satisfaction.size()-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int include = satisfaction[i]*(j+1)+dp[i+1][j+1];
                int exclude = dp[i+1][j];
                dp[i][j]=max(include,exclude);
            }
        }

        return dp[0][0];
    }
};