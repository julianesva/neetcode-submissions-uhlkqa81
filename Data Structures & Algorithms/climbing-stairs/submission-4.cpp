class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2; 

        // int prev = 1;
        // int curr = 2; 

        vector<int>dp;
        dp.push_back(1);
        dp.push_back(2);


        for(int i = 2; i < n; i++){
            dp.push_back(dp[i-2] + dp[i-1]);
            // int temp = prev;
            // prev = curr; 
            // curr = temp + curr;
        }

        return dp[n-1]; 
    }
};