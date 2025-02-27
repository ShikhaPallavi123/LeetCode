class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPrice = 0;
        for(int i = 0; i < prices.size(); i++){
            int price = prices[i];
            minPrice = min(minPrice, price);
            maxPrice = max(maxPrice, price-minPrice);
        }
        return maxPrice;
    }
};