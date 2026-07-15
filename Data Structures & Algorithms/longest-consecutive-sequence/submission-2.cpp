class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        st.insert(nums.begin(), nums.end());
        int longest = 0;
        

         for (int num : st) {
            if(!st.contains(num-1)) {
                int current = num;
                int length = 1;
                while(st.contains(current+1)) {
                    length++;
                    current++;
                }
                longest = max(longest, length);
            }
         }
        return longest;
    }
};
