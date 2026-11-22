class Solution {
public:
    bool checkString(string s) {
        int i=0;

        while(s[i]=='a')
            i++;

        for(;i<s.length();i++){
            if(s[i]=='a')
                return false;
        }

        return true;
    }
};