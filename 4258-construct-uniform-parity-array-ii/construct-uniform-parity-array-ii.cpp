class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());

        if(nums1[0]%2)
            return true;
            
        for(int num:nums1){
            if(num%2!=0)
                return false;
        }

        return true;
    }
};