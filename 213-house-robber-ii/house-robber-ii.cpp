class Solution {
public:

    int rob(vector<int>& nums, int f, int L) {

        vector<int> dp(nums.size(), 0);

        dp[L] = nums[L];

        for(int i = L - 1; i >= f; i--) {

            int maxx = 0;

            for(int j = i + 2; j <= L; j++) {
                maxx = max(dp[j], maxx);
            }

            dp[i] = max(dp[i + 1], nums[i] + maxx);
        }

        return dp[f];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        return max(
            rob(nums, 0, n - 2),
            rob(nums, 1, n - 1)
        );
    }
};