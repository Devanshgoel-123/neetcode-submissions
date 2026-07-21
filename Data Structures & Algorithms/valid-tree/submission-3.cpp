class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        if (edges.size() != n - 1) return false;
        for (auto p : edges) {
            int v1= p[0];
            int v2 = p[1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        queue<pair<int,int>> q;
        q.push({0, -1});
        vis[0] = 1;
        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push({nei, node});
                }
                else if (nei != parent) {
                    return false;
                }
            }
        }
        for (int x : vis)
            if (!x)
                return false;

        return true;
    }
};
