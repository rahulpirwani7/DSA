class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> hash;

        for (int num : arr)
            hash[num]++;

        vector<int> temp;

        for (auto p : hash)
            temp.push_back(p.second);

        sort(temp.begin(), temp.end(), greater<int>());

        int i = 0;
        int half = (arr.size() + 1) / 2;

        while (half > 0) {
            half -= temp[i];
            i++;
        }

        return i;
    }
};