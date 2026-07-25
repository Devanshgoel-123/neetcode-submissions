class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap; 
        int count=0;
        for(auto stone:stones) {
            maxHeap.push(stone);
            count++;
        }
        while(count > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            int diff = stone1-stone2;
            count = diff == 0 ? count-2 : count-1;
            if( diff > 0) {
             maxHeap.push(diff);
            }
        }
        return count == 0 ? 0 : maxHeap.top();
    }
};
