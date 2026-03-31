class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max_profit = 0; 
        int buy_ind = 0;

        for(int stock = 1; stock < prices.size(); stock++){
            if(prices[buy_ind] < prices[stock]){
                max_profit = max(max_profit, prices[stock] - prices[buy_ind]);
            }
            else{
                buy_ind += stock - buy_ind;
            }
        }
        return max_profit;
    }
};
