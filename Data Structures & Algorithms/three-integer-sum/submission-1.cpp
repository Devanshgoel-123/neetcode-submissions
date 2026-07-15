class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int high = nums.size()-1;    
            int mid = i+1;
            while(mid < high) {
                 int sum = nums[i] + nums[mid] + nums[high];
                 if( sum == 0) {
                    result.push_back({nums[i], nums[mid], nums[high]});
                    while (mid < high && nums[mid] == nums[mid+1]) mid++;
                    while (mid < high && nums[high] == nums[high-1]) high--;
                    mid++;
                    high--;
                 }else if(sum > 0) {
                    high--;
                 } else{
                    mid++;
                 }
            }
        }
        return result;
    }
};
