class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int idx=0;
        int count=nums[0];
        vector<int> ans;

        while(idx!=nums.size()){
            if(nums[idx]==count)
                idx++;
            else
                ans.push_back(count);

            count++;
                

        }

        return ans;
    }
};