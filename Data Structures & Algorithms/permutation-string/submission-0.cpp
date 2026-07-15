class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        for(char c:s1) {
            f1[c-'a']++;
        }
        int low=0;
        int high=1;
        for (int high = 0; high < s2.size(); high++) {
            f2[s2[high] - 'a']++;
            if (high - low + 1 > s1.size()) {
                f2[s2[low] - 'a']--;
                low++;
            }
            if (high - low + 1 == s1.size()) {
                if (f1 == f2)
                    return true;
            }
        }
        return false;
    }
};
