class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right) {
            while(!isValid(s[left])) left++;
            if(left >= right) break;
            while(!isValid(s[right])) right--;
            if(left >= right) break;
            if(process(s[left]) != process(s[right]) ) return false;
            left++;
            right--;
        }
        return true;
    }

    char process(char c) {
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) return c;
        return c - 'A' + 'a';
    }

    bool isValid(char c) {
        if(c >= 'A' && c <= 'Z') return true;
        if(c >= 'a' && c <= 'z') return true;
        if(c >= '0' && c <= '9') return true;
        return false;
    }
};
