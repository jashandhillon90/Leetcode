class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxpro=0,bestbuy=prices[0];
       for(int i=0;i<prices.size();i++){
        if(prices[i]>bestbuy){
            maxpro=max(maxpro,prices[i]-bestbuy);
        }
        bestbuy=min(bestbuy,prices[i]);
       } 
       return maxpro;
    }
};