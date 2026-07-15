class Solution {
public:
    void pickNotPick(vector<int>& nums, int index,vector<int>& current,vector<vector<int>>&result) {
        if(index == nums.size()){
            result.push_back(current);
            return;
        }
        //pick
        current.push_back(nums[index]);
        pickNotPick(nums, index+1, current, result);
        current.pop_back();
        //notpick
        pickNotPick(nums, index+1, current, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        pickNotPick(nums, 0, current, result);
        return result;
    }
};
