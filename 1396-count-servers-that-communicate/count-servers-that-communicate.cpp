class Solution {
public:

    int dfs(vector<vector<int>>& grid,int x,int y,vector<vector<bool>> &vis){
        if(grid.size()==x || y==grid[0].size())
                return 0;

        int count=0;
        vis[x][y]=true;
        for(int i=0;i<grid.size();i++){
                if(vis[i][y]==false && grid[i][y]==1 && i!=x){
                   
                    count+=1+dfs(grid,i,y,vis);
                }
        }

        for(int i=0;i<grid[0].size();i++){
            if(vis[x][i]==false && grid[x][i]==1 && i!=y){
               
                count+=1+dfs(grid,x,i,vis);
            }
        }

        return count;
    }
    int countServers(vector<vector<int>>& grid) {
       vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==false && grid[i][j]){
                    int newcount=dfs(grid,i,j,vis);
                    if(newcount)
                        count++;
                    
                    count+=newcount;
                }
                    
            }
        }
        return count;
    }
};