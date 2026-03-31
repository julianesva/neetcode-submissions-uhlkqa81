class Solution {
// private: 
    // vector<int> memo;
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        // memo.resize(nums.size(), -1);
        // vector<int> dp(nums.size());
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            int temp = max(b, nums[i] + a);
            a = b;
            b = temp;
        }
        return b;
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