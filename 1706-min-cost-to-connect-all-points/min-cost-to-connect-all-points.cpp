class Solution {
public:

    struct DSU{
        vector<int> par;
        vector<int> rank;

        DSU(int n){
            par.resize(n);
            rank.resize(n);

            for(int i=0;i<n;i++){
                par[i]=i;
                rank[i]=0;
            }
        }

        int find(int x){
            if(par[x]==x)
                return x;

            return find(par[x]);
        }

        void unione(int a,int b){
            int parA=find(a);
            int parB=find(b);

            if(parA==parB)
                return ;
            

            if(rank[parA]==rank[parB]){
                par[parB]=parA;
                rank[parA]++;
            }
            else if(rank[parA]==rank[parB])
                par[parB]=parA;
            else
                par[parA]=parB;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<tuple<int,int,int>> edges;

        for(int i=0;i<n;i++){
            for(int  j=i+1;j<n;j++){
                int dis=abs(points[i][0]-points[j][0]) +abs(points[i][1]-points[j][1]);

                edges.push_back({dis,i,j});
            }
        }

        int cost=0;
        sort(edges.begin(), edges.end());
        DSU dsu(n);

        for(auto [w,u,v]:edges){
            if(dsu.find(u)!=dsu.find(v)){
                cost+=w;
                dsu.unione(u,v);
            }

        }

        return cost;
    }
};