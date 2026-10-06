class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int open=0;
        int count=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('){
                open++;
            }
            else{
                if(open==0){
                    count++;
                }
                else{
                    open--;
                }
            }
        }
        return open+count;
    }
};