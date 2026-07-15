class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(string str:strs) {
            int size = str.length();
            encoded = encoded+to_string(size)+'#'+str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0; 
        while(i < s.size()) {
            string l="";
            while( s[i] != '#'){
             l.push_back(s[i]);
             i++;
            }
            int length = stoi(l);
            i++;
            string str="";
            while (length > 0) {
                str.push_back(s[i]);
                i++;
                length--;
            }
            result.push_back(str);
        }
        return result;
    }
};
