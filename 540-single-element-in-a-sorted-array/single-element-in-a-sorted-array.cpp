class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while( low < high ){
            int mid = low + (high - low)/2;

            int rightSize = high - mid;

            if( (rightSize & 1) == 1 and nums[mid] == nums[mid + 1]){
                high = mid - 1;
            } else if ( (rightSize & 1) == 1 and nums[mid] != nums[mid + 1]){
                low = mid + 1;
            } else if( (rightSize & 1) == 0 and nums[mid] == nums[mid + 1]){
                low = mid + 2;
            } else if( (rightSize & 1) == 0 and nums[mid] != nums[mid + 1]){
                high = mid ;
            }
        }

        return nums[low];
    }
};