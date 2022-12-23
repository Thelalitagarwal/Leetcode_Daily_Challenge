class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if(l < 2)  return 0;

        int donothing1 = -prices[0];
        int sell1 = 0;
        int donothing0 = 0;
        int buy0 = -prices[0];
        for(int i=1; i<l; i++) {
            donothing1 = donothing1 > buy0 ? donothing1 : buy0;
            buy0 = -prices[i] + donothing0;
            donothing0 = donothing0 > sell1 ? donothing0 : sell1;
            sell1 = prices[i] + donothing1;
        }
        return sell1 > donothing0 ? sell1 : donothing0;
    }
  
};