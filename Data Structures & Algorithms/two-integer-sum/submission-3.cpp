class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> complement_map;

        for(int j = 0; j < nums.size(); j++){
            if(complement_map.count(target - nums[j])){
                return {complement_map[target - nums[j]], j};
            }
            complement_map[nums[j]] = j;
        }
        return {};
    }
};
