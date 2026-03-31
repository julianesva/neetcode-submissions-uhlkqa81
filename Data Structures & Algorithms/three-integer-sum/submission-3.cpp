class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if(nums.size() < 3){
            return {};
        }

        sort(nums.begin(), nums.end());

        
        vector<vector<int>> results;
        
        for(int i = 0 ; i < nums.size()-2; i++){
            int spoted = nums[i];
            int left = i + 1; 
            int right = nums.size()-1;
            if(i > 0 && nums[i-1] == spoted) continue;
            while(left < right){
                int result = spoted + nums[right] + nums[left];
                if(result == 0){
                    results.push_back({spoted, nums[right], nums[left]});
                    right--;
                    left++;
                    while(left < right && nums[left] == nums[left-1])
                        left++;

                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }
                else if(result > 0){
                    right--;
                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }
                else{
                    left++;
                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }
            }
        }

        return results;
    }
};
