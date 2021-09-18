/*
一遍遍历：
    对于每天的股票价格，都要问一遍自己，今天的股票价格是最低的吗，今天的股票卖的话利润会更大吗
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profile = 0;
        int min_price = 1000000000;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            if (prices[i] - min_price > max_profile) {
                max_profile = prices[i] - min_price;
            }
        }       
        return max_profile;
    }
};