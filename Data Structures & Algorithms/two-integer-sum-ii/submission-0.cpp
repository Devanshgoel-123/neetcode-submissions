class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> s;
        vector<int> result;
        for(int i=0; i < numbers.size(); i++) {
            if (s.contains(target - numbers[i])) {
                result.push_back(s[target - numbers[i]]);
                result.push_back(i+1);
            }else{
                s.insert({numbers[i], i+1});
            }
        }
        return result;
    }
};
