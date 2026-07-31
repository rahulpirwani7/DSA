class Solution {
public:
    int reverseDegree(string s) {
        int product=0;

        for(int i=0;i<s.length();i++)
            product+=( 26 - (s[i]-'a') ) *(i+1);

        return product;
    }
};