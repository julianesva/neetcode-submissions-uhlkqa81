class Solution {
public:
    int findMin(vector<int> &nums) {

        int right = nums.size() / 2;
        int left = 0; 

        while(right < nums.size()){
            if(nums[left] > nums[right]){
                while(nums[right] > nums[right-1]){
                    right--;
                }
                return nums[right];
            }
            left++;
            right++;
        }

        return nums[0];
        
    }
};
