class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bday =0;
        int maxprofit = 0;
        for(int i =1;i<prices.size();i++){
           if(prices[i] < prices[bday]){bday = i ;}
           int profit = prices[i] - prices[bday] ;
           maxprofit = max(maxprofit, profit);

        }
   return maxprofit ; }
};