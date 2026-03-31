class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sz = nums.size();

        for(int i = 0; i < sz-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }

        return false;
    }
};