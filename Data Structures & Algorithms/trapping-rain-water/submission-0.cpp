class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater =0;
        int n = height.size();
        for(int i =0; i < height.size(); i++) {
            int maxLeft = 0;
            int maxRight = 0;
            for (int j = 0; j <= i; j++) {
                maxLeft = max(maxLeft, height[j]);
            }
            for (int j = i; j < n; j++) {
                maxRight = max(maxRight, height[j]);
            }

            int waterLevel = min(maxLeft, maxRight);
            totalWater += waterLevel - height[i];
        }
        return totalWater;
    }
};
