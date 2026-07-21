class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visArr(n,0);
        vector<vector<int>> adjList(n);
        int count=0;
        for (auto p : edges) {
            int v1= p[0];
            int v2 = p[1];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        
        for(int i=0; i< n;i++) {
            if(!visArr[i]){
                count++;
                queue<pair<int,int>> q;
                q.push({i,-1});
                bfs(adjList, visArr, q);
            }
        }   
        return count;
    }

    void bfs(vector<vector<int>> &adjList,vector<int> &visArr, queue<pair<int,int>> &q) {
        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for(auto nei : adjList[node]) {
                if(!visArr[nei]) {
                    visArr[nei] = 1;
                    q.push({nei, node});
                }
            }
        }
    }
};
