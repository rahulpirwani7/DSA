class Solution {
public: 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n,INT_MAX);
        dis[src]=0;

        for(int i=0;i<=k;i++){
            vector<int> temp=dis;
            for(auto & edge:flights){
                // if(count==k)
                //     break;
                int u=edge[0];
                int v=edge[1];
                int wei=edge[2];

                if(dis[u]!=INT_MAX && dis[u]+wei<temp[v]){
                    temp[v]=dis[u]+wei;
                }
            }
            dis=temp;
        }

        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};