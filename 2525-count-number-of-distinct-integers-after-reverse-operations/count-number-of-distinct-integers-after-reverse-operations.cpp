class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto i : nums) {
            int j = 0;
            while(i) {
                j = j * 10 + (i % 10);
                i /= 10;
            }
            st.insert(j);
        }
        return (int)st.size();
    }
};