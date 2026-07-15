class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMp;
        vector<int> ans;
        for(int i:nums){
            countMp[i]++;
        }
        vector<pair<int,int>> vec;
        for(auto &[num, count] : countMp) {
            vec.push_back({num, count});
        }
        sort(vec.begin(), vec.end(),
        [](const auto &a, const auto &b) {
            return a.second > b.second;
        });
        for(int i = 0; i < k; i++) {
        ans.push_back(vec[i].first);
        }
        return ans;
    }
};
