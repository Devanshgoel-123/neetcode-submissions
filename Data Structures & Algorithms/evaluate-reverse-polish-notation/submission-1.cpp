class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for(string c:tokens) {
            if(c != "+" && c != "-" && c != "*" && c != "/") {
                st.push(stoi(c));
            }else{
                string currentOperand = c;
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                int temp = resolve(val1, val2, currentOperand);
                st.push(temp);
            }
        }
        return st.top();
    }

    int resolve(int val1, int val2, string exp) {
        if(exp == "+"){
            return val1+val2;
        }else if(exp == "-"){
            return val1-val2;
        }else if(exp == "*"){
            return val1*val2;
        }else{
            return val1/val2;
        }
    }
};
