class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool canFinish=false;
        int n = numCourses;
        vector<vector<int>> adjList(n);
        for (auto &p : prerequisites) {
            int course = p[0];
            int preReq = p[1];
            adjList[course].push_back(preReq);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        for (int course = 0; course < numCourses; course++) {
            if(dfs(course, adjList, visited, path)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course, vector<vector<int>>& adjList,
    vector<bool>& visited, vector<bool>& path) {
        if(visited[course]) return false;
        if(path[course]) return true;
        path[course] = true;
        for(int preReq : adjList[course] ) {
           if (dfs(preReq, adjList, visited, path))
                return true;
        }
        path[course] = false;
        visited[course] = true;
        return false;
    }
};
