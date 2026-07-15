class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> answer(n, 0);
      int result = 1;
      int zeroCount=0;

      for(int i=0; i < n; i++) {
         if(nums[i] == 0) zeroCount++;
         else result = result * nums[i];
      }

      if(zeroCount > 1) {
        return answer;
      }
      
      if(zeroCount == 1 ) {
        for(int i=0; i < n; i++) {
            if(nums[i] == 0){
                answer[i] = result;
                return answer;
            }
        }
      }
      for(int i=0; i < n; i++) {
        answer[i]=result / nums[i];
      }
      return answer;
    }
};
