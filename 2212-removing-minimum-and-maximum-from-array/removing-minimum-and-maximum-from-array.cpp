class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int changeIndex=1;
        int mx=0;
        int mn=0;

        for(int i=1;i<nums.size();i++){
            if(nums[mx] < nums[i])
                mx=i;
            else if(nums[mn] > nums[i])
                mn=i;
        }

        int p1=max(mn,mx)+1;
        int p2=nums.size()-min(mn,mx);
        int p3=min(mx,mn)+nums.size()-max(mn,mx)+1;


        return min(p1,min(p2,p3));
    }
};