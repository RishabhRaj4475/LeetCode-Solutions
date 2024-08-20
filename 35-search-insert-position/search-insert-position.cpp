class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0 ; int high = nums.size() - 1;
        int ans = -1 ;

        while( low <= high){
            int mid = low + ( high - low )/2;
            if(nums[mid] <= target){
                ans = max(ans , mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans == -1 ? 0 : (nums[ans] < target ? ans + 1 : ans);
    }
};