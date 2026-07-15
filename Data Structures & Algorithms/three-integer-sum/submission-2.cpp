class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i < nums.size();i++) {
            if(i > 0 && nums[i]==nums[i-1]) continue;
            int mid = i+1;
            int high = nums.size()-1;
            while( mid < high ){
                int sum = nums[i] + nums[mid] + nums[high];
                if( sum == 0) {
                    result.push_back({nums[i], nums[mid], nums[high]});
                    while(mid < high && nums[high] == nums[high-1]) high--;
                    while (mid < high && nums[mid] == nums[mid+1]) mid++;
                    high--;
                    mid++;
                }else if(sum > 0) {
                    high--;
                }else{
                    mid++;
                }
            }
        }
        return result;
    }
};
