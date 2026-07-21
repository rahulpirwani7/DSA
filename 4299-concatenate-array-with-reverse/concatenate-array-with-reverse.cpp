class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans(nums.size()*2);

        for(int i=0;i<nums.size();i++)
            ans[i]=ans[ans.size()-1-i]=nums[i];

        return ans;
    }
};