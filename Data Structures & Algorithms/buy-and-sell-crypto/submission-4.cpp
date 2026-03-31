class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max_profit = 0; 
        int buy_ind = 0;

        for(int stock = 1; stock < prices.size(); stock++){
            if((prices[stock] - prices[buy_ind]) > max_profit){
                max_profit = prices[stock] - prices[buy_ind];
            }
            else if(prices[stock] < prices[buy_ind]){
                buy_ind = stock;
            }
        }
        return max_profit;
    }
};
