class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);

        int n=nums.size();
        dp[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            
            int maxx=0;
            for(int j=i+2;j<n;j++)
                maxx=max(dp[j],maxx);

            dp[i]=max(dp[i+1],nums[i]+maxx);
        }


        return dp[0];

    }
};