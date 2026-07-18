class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());
        

        for(int i=0;i<times.size();i++)
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        

       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  hp;
        hp.push({0,k});
        vector<bool> vis(n+1,true);
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;

        while(!hp.empty()){ 
            auto temp=hp.top();
            hp.pop();
            vis[temp.second]=false;
           
            for(int i=0;i<graph[temp.second].size();i++){
                if(vis[graph[temp.second][i].first]){
                if(temp.first +graph[temp.second][i].second <
                    dis[graph[temp.second][i].first]){
                        dis[graph[temp.second][i].first]=temp.first +graph[temp.second][i].second;
                        hp.push({dis[graph[temp.second][i].first],graph[temp.second][i].first});
                }
                
                }
            }
        
        }

        int maxx=-1;
        for(int i=1;i<dis.size();i++){
            maxx=max(maxx,dis[i]);
        }


        return maxx==INT_MAX?-1:maxx;
    }
};