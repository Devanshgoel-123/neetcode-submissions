class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> visArr(n, 0);
        if (edges.size() != n - 1) return false;
        for (auto p : edges) {
            int v1= p[0];
            int v2 = p[1];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        for(int i=0; i < n; i++) {
            if(!visArr[i]) {
                visArr[i] = 1;
                for(auto it:adjList[i]) {
                    if(!dfs(i, visArr, adjList, it)) {
                        return false;
                    }
                } 
            }
        }
        return true;
    }

    bool dfs(int parent, vector<int> &visArr,vector<vector<int>>& adjList, int node) {
        if(visArr[node] == 1 && node!= parent ) return false;
        visArr[node] =1;
        if(adjList[node].size() == 0) return true;
        for(auto it:adjList[node]) {
           if (it != parent) {
                if (!dfs(node, visArr, adjList, it)) return false;
            }
        }
        return true;
    }
};
