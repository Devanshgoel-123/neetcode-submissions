class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        //store index in the stack
        stack<int> st;
        for(int i=0; i < temperatures.size();i++) {
            if(st.empty()) {
                st.push(i);
            }else{
                int temp = st.top();  
                while(!st.empty() && temperatures[temp] < temperatures[i]) {
                    result[temp] = i-temp;
                    st.pop();
                    temp = st.top();
                }
                st.push(i);
            }
        }
        return result;
    }
};
