class MinStack {
public:
   vector<int> st;
   stack<int> minSt;
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if(st.back() == minSt.top()) {
            minSt.pop();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.top();
    }
};
