class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        int startIndex = 0;
        set<char> st;
        for(int i=0; i < s.size(); i++) {
            while (st.contains(s[i])) {
                st.erase(s[startIndex]);
                startIndex++;
            }
            st.insert(s[i]);
            maxSize = max(maxSize, i - startIndex + 1);
        }
        return maxSize;
    }
};
