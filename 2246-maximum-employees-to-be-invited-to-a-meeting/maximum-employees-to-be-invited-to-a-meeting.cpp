class Solution {
public:
    vector<vector<int>> graph, rev;
    vector<int> order;
    vector<int> comp;
    vector<bool> vis;

    void dfs1(int u) {
        vis[u] = true;
        for (int v : graph[u])
            if (!vis[v]) dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u, vector<int>& component) {
        vis[u] = true;
        component.push_back(u);
        comp[u] = component[0];
        for (int v : rev[u])
            if (!vis[v]) dfs2(v, component);
    }

    int maximumInvitations(vector<int>& favorite) {

        int n = favorite.size();

        graph.assign(n, {});
        rev.assign(n, {});

        for (int i = 0; i < n; i++) {
            graph[i].push_back(favorite[i]);
            rev[favorite[i]].push_back(i);
        }

        vis.assign(n, false);

        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs1(i);

        reverse(order.begin(), order.end());

        vis.assign(n, false);
        comp.assign(n, -1);

        vector<vector<int>> sccs;

        for (int node : order) {
            if (!vis[node]) {
                vector<int> component;
                dfs2(node, component);
                sccs.push_back(component);
            }
        }

        int largestCycle = 0;
        int twoCycleAnswer = 0;

        for (auto &scc : sccs) {

            if (scc.size() > 2) {
                largestCycle = max(largestCycle, (int)scc.size());
            }

            else if (scc.size() == 2) {

                int a = scc[0];
                int b = scc[1];

                auto longestChain = [&](int start, int ban) {

                    function<int(int)> dfs = [&](int u) {

                        int best = 0;

                        for (int v : rev[u]) {

                            if (v == ban) continue;
                            if (comp[v] == comp[start]) continue;

                            best = max(best, dfs(v));
                        }

                        return best + 1;
                    };

                    return dfs(start) - 1;
                };

                int left = longestChain(a, b);
                int right = longestChain(b, a);

                twoCycleAnswer += left + right + 2;
            }
        }

        return max(largestCycle, twoCycleAnswer);
    }
};