class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto &v : knowledge)
            mp[v[0]] = v[1];

        bool brac = false;
        string ans = "";
        string temp = "";

        for (char ch : s) {
            if (ch == '(') {
                brac = true;
                continue;
            }

            if (ch == ')') {
                ans += mp.count(temp) ? mp[temp] : "?";
                temp = "";
                brac = false;
                continue;
            }

            if (brac)
                temp += ch;
            else
                ans += ch;
        }

        return ans;
    }
};