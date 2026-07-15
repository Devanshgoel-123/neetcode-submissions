class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>>mp;
        for(string &s:strs) {
            string resultingKey = findKeyForStr(s);
            mp[resultingKey].push_back(s);
        }
        vector<vector<string>> answer;
        for(auto &[k,v] : mp) {
            answer.push_back(v);
        }
        return answer;
    }

    string findKeyForStr(string &s) {
        vector<int> countArr(26);
        for(char c:s) {
           countArr[c -'a']++;
        }
        string key = "";
        key.reserve(80);
        for(int x:countArr){
            key.append(to_string(x));
            key.push_back('#');
        }
        return key;
    }
};
