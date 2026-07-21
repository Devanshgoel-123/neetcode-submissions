class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjList(n);
        vector<int> cycleDetection;
        for (auto &p : prerequisites) {
            int course = p[0];
            int preReq = p[1];
            adjList[preReq].push_back(course);
        }
        vector<int> inDeg = vector<int>(n,0);
        for(int i=0; i < n; i++) {
            for( auto it: adjList[i]) {
                inDeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i < n; i++) {
            if(!inDeg[i]) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            for(auto it: adjList[node]) {
                inDeg[it]--;
                if(!inDeg[it]) q.push(it);
            }
            q.pop();
            cycleDetection.push_back(node);
        }

        return cycleDetection.size() == numCourses;
    }
};
