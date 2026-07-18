class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int  n1=nums[0];
        int  n2=nums[nums.size()-1];

        while(n2%n1){
            int temp=n1;
            n1=n2%n1;
            n2=temp;
        }

        return n1;
    }
};