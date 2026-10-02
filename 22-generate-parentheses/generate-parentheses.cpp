class Solution {
public:
    void helper(vector<string> &out, int n,int clo,string temp ){
        if(0==n){
            for(int i=0;i<clo;i++)
                temp+=')';
            out.push_back(temp);
            return ;
        }
        
        helper(out,n-1,clo,temp+'(');

        if(clo-n>0)
            helper(out,n,clo-1,temp+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        helper(res,n,n,temp);
        return res;
    }
};