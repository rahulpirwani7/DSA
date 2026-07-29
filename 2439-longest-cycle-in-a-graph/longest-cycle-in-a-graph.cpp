class Solution {
public:
    void dfs1(int node, vector<vector<int>>& graph,
              vector<bool>& vis, stack<int>& st) {
        vis[node] = true;

        for (int neigh : graph[node]) {
            if (!vis[neigh])
                dfs1(neigh, graph, vis, st);
        }

        st.push(node);
    }

    int dfs2(int node, vector<vector<int>>& revGraph,
             vector<bool>& vis) {
        vis[node] = true;
        int cnt = 1;

        for (int neigh : revGraph[node]) {
            if (!vis[neigh])
                cnt += dfs2(neigh, revGraph, vis);
        }

        return cnt;
    }

    int longestCycle( vector<int>& edges) {
        int V=edges.size();
        vector<vector<int>> graph(V), revGraph(V);

        for (int i = 0; i < V; i++) {
            if (edges[i] != -1) {
                graph[i].push_back(edges[i]);
                revGraph[edges[i]].push_back(i);
            }
        }

        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs1(i, graph, vis, st);
        }

        fill(vis.begin(), vis.end(), false);

        int largestSCC = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                int size = dfs2(node, revGraph, vis);
                largestSCC = max(largestSCC, size);
            }
        }

        return largestSCC==1?-1:largestSCC;
    }
};