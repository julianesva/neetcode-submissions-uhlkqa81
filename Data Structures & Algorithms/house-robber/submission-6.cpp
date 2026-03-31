class Solution {
// private: 
    // vector<int> memo;
public:
    int rob(vector<int>& nums) {
        // memo.resize(nums.size(), -1);
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[nums.size()-1];
    }

    // int dfs(vector<int>& nums, int i) {
    //     if( i >= nums.size()){
    //         return 0; 
    //     }
    //     else if(memo[i] != -1){
    //         return memo[i];
    //     }
    //     else{
    //         memo[i] = max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
    //         return memo[i];
    //     }
    // }
};