class Solution {
public:
    void pickNotPick(vector<int>&current, vector<int>& nums, int target, int sum, int index,vector<vector<int>>& result) {
        if(target == sum) {
            result.push_back(current);
            return;
        }
        if (sum > target || index == nums.size()) return;
        //notPick
        pickNotPick(current, nums, target, sum, index+1, result);
        //pick
        current.push_back(nums[index]);
        sum+= nums[index];
        pickNotPick(current, nums, target, sum, index, result);
        current.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        pickNotPick(current, nums, target, 0, 0, result);
        return result;
    }
};
