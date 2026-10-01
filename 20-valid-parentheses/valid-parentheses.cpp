class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;

        for(int i=0;i<s.length();i++){

            if(!ss.empty() && ((ss.top()=='(' && s[i]==')') || (ss.top()=='{' && s[i]=='}') ||
(ss.top()=='[' && s[i]==']') ) )
                ss.pop();
            else
            ss.push(s[i]);
        }

        return ss.empty();
    }
};