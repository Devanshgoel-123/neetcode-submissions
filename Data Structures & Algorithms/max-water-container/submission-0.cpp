class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        for(int i=0; i < heights.size() - 1; i++) {
            for(int j = i+1; j < heights.size(); j++) {
                int left = heights[i];
                int right = heights[j];
                int tempHeight = min(left, right);
                int baseWidth = j-i;
                int tempArea = baseWidth * tempHeight;
                maxArea = max(maxArea, tempArea);
            }
        }
        return maxArea;
    }
};
