class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMp;
        vector<int> ans;
        for(int i:nums){
            countMp[i]++;
        }
        vector<vector<int>> vec;
        for(auto &[num, freq] : countMp) {
            vec.push_back({num, freq});
        }
        sort(vec.begin(), vec.end(),
        [](const auto &a, const auto &b) {
            return a[1] > b[1];
        });
        for(int i = 0; i < k; i++) {
        ans.push_back(vec[i][0]);
        }
        return ans;
    }
};
