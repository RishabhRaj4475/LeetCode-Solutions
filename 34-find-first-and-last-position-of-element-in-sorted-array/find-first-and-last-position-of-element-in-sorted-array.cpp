class Solution {
public:

    int helper1(vector<int>& nums , int target){
        int n = nums.size();
        int low = 0 ; int high = n - 1;
        int ans = n;

        while(low <= high){
            int mid = low + ( high - low )/2;

            if(nums[mid] == target){
                ans = min( ans , mid);
                high = mid - 1;
            } else if( nums[mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans == n ? -1 : ans;
    }

    int helper2(vector<int>&nums , int target){
        int n = nums.size();
        int low = 0 , high = n - 1;

        int ans = -1;

        while(low <= high){
            int mid = low + ( high - low)/2;

            if( nums[mid] == target){
                ans = max(ans , mid);
                low = mid + 1;
            } else if( nums[mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = helper1(nums , target);
        int end = helper2(nums , target);

        if(start == -1 or end == -1) return {-1 , -1};

        return {start , end};
        
    }
};