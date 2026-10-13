class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]*nums[i];

        long long ans=0;

        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());

        while(i<=j){
            ans+=nums[j];
            if(i!=j)
                ans-=nums[i];

            j--;
            i++;
        }

        return ans;
        
    }
};