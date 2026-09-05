class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> minArr(nums.size());
        minArr[nums.size()-1]=nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--)
            minArr[i]=min(nums[i],minArr[i+1]);

        int maxx=0;

        for(int i=0;i<nums.size();i++){
            maxx=max(maxx,nums[i]);

            if(maxx-minArr[i] <=k)
                return i;
        }

        return -1;
        
    }
};