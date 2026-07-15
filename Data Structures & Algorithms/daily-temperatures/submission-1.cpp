class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indexSt;
        vector<int> result(temperatures.size(), 0);
        for(int i=0; i< temperatures.size();i++) {
            if(indexSt.empty()) {
                indexSt.push(i);
            }else{
                int tempIndex = indexSt.top();
                while(!indexSt.empty() && temperatures[tempIndex] < temperatures[i]) {
                    result[tempIndex] = i - tempIndex;
                    indexSt.pop();
                    tempIndex = indexSt.top();
                }
                indexSt.push(i);
            } 
        }
        return result;
    }
};
