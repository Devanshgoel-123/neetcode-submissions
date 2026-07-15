class Solution {
public:
    string minWindow(string s, string t) {
    string answer="";
    if(t.size() > s.size()) return answer;
    vector<int> f1(128,0);
    vector<int> f2(128,0);
      for(char c:t) {
        f1[c]++;
      }
      int minLen = INT_MAX;
      int low=0;
      int start = 0;
      for(int high=0; high < s.size(); high++) {
        f2[s[high]]++;
        while(isValid(f1, f2)) {
            if (high - low + 1 < minLen) {
                minLen = high - low + 1;
                start = low;
            }
            f2[s[low]]--;
            low++;
        } 
      }
      if (minLen == INT_MAX) return "";
      return s.substr(start, minLen);
    }

    bool isValid(vector<int>& f1, vector<int>& f2) {
        for (int i = 0; i < 128; i++) {
            if (f2[i] < f1[i])
                return false;
        }
        return true;
    }
};
