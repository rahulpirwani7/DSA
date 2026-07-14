class Solution {
public:
    int longestValidParentheses(string s) {
        int left1=0;
        int left2=0;
        int right1=0;
        int right2=0;

        int maxx=0;

        for (int i=0;i<s.length();i++){
            if(s[i]=='(')
                left1++;
            else 
                right1++;
            
            if(s[s.length()-1-i]=='(')
                left2++;
            else
                right2++;
            

            if(left1==right1)
                maxx=max(maxx,left1*2);
            else if(left1 < right1)
                left1=right1=0;

            if(left2 == right2)
                maxx=max(maxx,left2*2);
            else if(left2 > right2)
                left2=right2=0;
        }

        return maxx;
    }
};