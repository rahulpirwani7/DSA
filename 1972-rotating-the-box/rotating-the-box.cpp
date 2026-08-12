class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'.'));
        int i=0,j=0;

        while(i<m){
            int count=0;
            while(j<n && boxGrid[i][j]!='*'){
                if(boxGrid[i][j]=='#')
                    count++;
                j++;
            }

            for(int x=j-1;x>=0;x--){

                if(count==0)
                    break;
                
                ans[x][m-1-i]='#';
                count--;

            }
            if(j==n){
                i++;
                j=0;
            }else
                j++;
            
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(boxGrid[i][j]=='*')
                    ans[j][m-1-i]='*';
            }
        }

        return ans;
    }
};