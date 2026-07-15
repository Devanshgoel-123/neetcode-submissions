class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> setDuplicate; 
        for(int x: nums) {
            if( setDuplicate.find(x) != setDuplicate.end()) return true;
            setDuplicate.insert(x);
        }
        return false;
    }
};