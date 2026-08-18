class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int a=nums[0];
        int b=nums[nums.size()-1];

        if(k==nums.size()){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
    

        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==a)
                a=-1;
            if(nums[i]==b) 
                b=-1;
        }

    
        if(k==1){
            sort(nums.begin(),nums.end());
            unordered_map<int,int> hash;

            for(int i=nums.size()-1;i>=1;i--){
                if(nums[i]!=nums[i-1] && !hash[nums[i]])
                    return nums[i];
                
                hash[nums[i]]++;
            }

            return hash[nums[0]]==0?nums[0]:-1;
        }

        return a==b?-1:max(a,b);

    }
};