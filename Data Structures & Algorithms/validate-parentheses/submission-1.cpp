class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0) return false;
        stack<char> st;
        for(char c:s) {
            if( c == '(' || c == '{' || c=='[') {
                st.push(c);
            }else{
                if(st.empty()) return false;
                char latestOpenBracket = st.top();
                if(latestOpenBracket == '(' && c == ')') {
                    st.pop();
                } else if(latestOpenBracket == '[' && c == ']'){
                    st.pop();
                }else if(latestOpenBracket == '{' && c == '}') {
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
