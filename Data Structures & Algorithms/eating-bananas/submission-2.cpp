class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = piles[0];
        int answer=1;
        for(int x : piles){
            high = max(high, x);
        }
        int mid = 0;
        while(low <= high) {
            mid = low + (high -low)/2;
            int time =0;
            for(int i=0; i < n;i++) {
                time += ceil((double)piles[i]/mid);
            }
            if( time > h ) low = mid +1; 
            if ( time <= h) {
                high = mid-1;
                answer = mid;
            }
        }
        return answer;
    }
};
