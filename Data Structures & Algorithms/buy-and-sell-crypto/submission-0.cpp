class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        for(int i=0; i < prices.size()-1; i++) {
            for(int j=i; j < prices.size();j++) {
                maxProfit = max(prices[j]-prices[i], maxProfit);
            }
        }
        return maxProfit;
    }
};
