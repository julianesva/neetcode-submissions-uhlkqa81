class Solution {
private: 
    unordered_map<int, int> memo;
public:
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i) {
        if( i >= nums.size()){
            return 0; 
        }
        else if(memo.find(i) != memo.end()){
            return memo[i];
        }
        else{
            memo[i] = max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
            return memo[i];
        }
    }
};