class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end()); 
        while(maxHeap.size() > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            int diff = stone1-stone2;
            if( diff > 0) {
             maxHeap.push(diff);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
