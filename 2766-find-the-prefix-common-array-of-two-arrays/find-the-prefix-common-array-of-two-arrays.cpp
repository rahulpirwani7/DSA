class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,bool> Ah,Bh;

        vector<int> ans(A.size());

        Ah[A[0]]=true;
        Bh[B[0]]=true;

        ans[0]=A[0]==B[0]?1:0;

        for(int i=1;i<A.size();i++){
            ans[i]=ans[i-1];

            if(A[i]==B[i])
                ans[i]++;
           if(Bh[A[i]])
                ans[i]++;
            if(Ah[B[i]])
                ans[i]++;

            Ah[A[i]]=true;
            Bh[B[i]]=true;
        }

        return ans;

    }
};