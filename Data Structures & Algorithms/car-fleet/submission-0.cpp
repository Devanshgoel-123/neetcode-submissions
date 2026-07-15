class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> time(position.size());
        int count = 1;
        for(int i=0; i < position.size(); i++) {
            int distance = target - position[i];
            time[i] = {position[i],(double)distance/speed[i]};
        }
        sort(time.begin(), time.end());
        for(int i=time.size()-2; i >= 0; i--) {
            if(time[i].second <= time[i+1].second) time[i].second=time[i+1].second;
            else count++;
        }
        return count;
    }
};
