class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        while( low <= high ) {
            int mid = low + ( high - low)/2;
            if(nums[mid] == target) return mid;
            //left part is sorted
            if(nums[mid] > nums[high]) {
                if(nums[low] <= target && nums[mid] > target ) {
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            //right part is sorted
            else {
                if(target <= nums[high] && nums[mid] < target ) {
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
