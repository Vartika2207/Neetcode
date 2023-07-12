class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        
        while(start < end) {
            if(nums[start] <= nums[end])  // array is sorted since end-indexed element is greater
                return nums[start];
            
            int mid = (start+end)/2;
            if(nums[start] <= nums[mid]) // from start to mid array is sorted
                start = mid + 1;
            else
                end = mid;
        }
        return nums[start];    
    }
};
