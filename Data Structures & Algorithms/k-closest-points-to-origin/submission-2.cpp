class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        vector<vector<int>> answer;
        for(auto it:points) {
            int distance = returnDistance(it[0], it[1]);
            pq.push({distance, {it[0], it[1]}});       
        }
        for(int i=0; i < k; i++) {
            vector<int> element = pq.top().second;
            pq.pop();
            answer.push_back(element);
        } 
        return answer;
    }

    int returnDistance(int x, int y) {
       return x*x + y*y;
    }
};
