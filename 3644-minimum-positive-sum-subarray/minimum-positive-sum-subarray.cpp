class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> prefix(nums.size(),0);
        prefix[0]=nums[0];

        int ans=INT_MAX;

        for(int i=1;i<nums.size();i++)
            prefix[i]=prefix[i-1]+nums[i];
        

        for(int i=l;i<=r;i++){
            if(min(prefix[i-1],ans) > 0)
                    ans=min(prefix[i-1],ans);

            for(int j=i;j<nums.size();j++){
                if(min(ans,prefix[j]-prefix[j-i]) > 0)
                    ans=min(ans,prefix[j]-prefix[j-i]);
            }

        }

        return ans==INT_MAX?-1:ans;
    }
};