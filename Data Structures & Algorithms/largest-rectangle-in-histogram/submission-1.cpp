class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightSide(n,n);
        stack<int> rightSt;
        for(int i=0; i < n; i++) {
            while(!rightSt.empty() && heights[rightSt.top()] > heights[i]) {
                rightSide[rightSt.top()] = i;
                rightSt.pop();
            }
            rightSt.push(i);
        }
        vector<int> leftSide(n,-1);
        stack<int> leftSt;
        for(int i=n-1; i >= 0; i--) {
            while(!leftSt.empty() && heights[leftSt.top()] > heights[i]) {
                leftSide[leftSt.top()] = i;
                leftSt.pop();
            }
            leftSt.push(i);
        }
        int maxArea=0;
        for(int i=0; i <n; i++) {
           int width = rightSide[i]-leftSide[i]-1;
            maxArea = max(maxArea,heights[i] * width);
        }
        return maxArea;
    }
};
