class Solution {
public:
    int recursivefibo(int n, unordered_map<int,int>& memo){
        if(memo.count(n)){
            return memo[n];
        }
        memo[n] = recursivefibo(n-2, memo) + recursivefibo(n-1, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        unordered_map<int,int> memo{{1,1}, {2,2}};

        int result = recursivefibo(n, memo);

        return result;
    }
};