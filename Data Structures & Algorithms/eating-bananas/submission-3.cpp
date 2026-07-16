class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = piles[0];
        for(int x : piles){
            high = max(high, x);
        }
        int mid = 0;
        while( low <= high) {
            mid = low + (high-low)/2;
            int time =0;
            for(int i=0; i < piles.size(); i++) {
                time += ceil((double)piles[i]/mid);
            }
            if(time > h) {
               low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high+1;
    }
};
