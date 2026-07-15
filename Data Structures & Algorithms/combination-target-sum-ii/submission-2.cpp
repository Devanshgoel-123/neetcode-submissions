class Solution {
public:
    void pickNotPick(vector<int>&current, vector<int>& nums, int target, int sum, int index, vector<vector<int>>& result) {
        if (sum == target) {
            result.push_back(current);
            return;
        }
        if (sum > target || index == nums.size()) return;
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index])
            next++;
        // Not pick
        pickNotPick(current, nums, target, sum, next, result);

        // Pick
        current.push_back(nums[index]);
        pickNotPick(current, nums, target, sum + nums[index], index + 1, result);
        current.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        pickNotPick(current, candidates, target, 0, 0, result);
        return result;
    }
};
