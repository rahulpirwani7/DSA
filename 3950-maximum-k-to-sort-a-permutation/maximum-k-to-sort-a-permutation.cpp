class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> newarr = nums;
        sort(newarr.begin(), newarr.end());

        vector<int> notperfect;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != newarr[i])
                notperfect.push_back(newarr[i]);
        }

        if (notperfect.empty())
            return 0;

        int n = notperfect[0];
        int solution = 0;

        for (int k = 1; k <= n; k++) {
            bool ans = true;

            for (int i = 0; i < notperfect.size(); i++) {
                if ((notperfect[i] & k) != k) {
                    ans = false;
                    break;
                }
            }

            if (ans)
                solution = max(solution, k);
        }

        return solution;
    }
};