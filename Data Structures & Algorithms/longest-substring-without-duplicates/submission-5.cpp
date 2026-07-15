class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string demoString="";
        int maxSize = 0;
        int startIndex = 0;
        int endIndex = 0;
        for(char c:s) {
            endIndex++;
            if(!demoString.contains(c)) {
                demoString.push_back(c);
            }else{
                while(s[startIndex] != c) {
                    startIndex++;
                }
                startIndex++;
                demoString = s.substr(startIndex, endIndex - startIndex);
            }
            maxSize = max(maxSize, endIndex - startIndex);
        }
        return maxSize;
    }
};
