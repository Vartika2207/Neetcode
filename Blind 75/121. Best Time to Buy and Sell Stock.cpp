class Solution {
public:
    
    //tle --O(n^2)
    int maxProfitHelper1(vector<int>& prices){
        int maxp=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                int profit=prices[j] - prices[i];
                if(profit>maxp) maxp=profit;
            }
        }
        return maxp;
    }
    
    //O(n)
    int maxProfitHelper2(vector<int>& prices){
        int minVal=INT_MAX;
        int maxP=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minVal){
                minVal=prices[i];
            }
            else if(prices[i]-minVal > maxP){
                maxP=prices[i]-minVal;
            }
        }
        return maxP;
    }
    
    int maxProfit(vector<int>& prices) {
        return maxProfitHelper2(prices);
    }
    
   
};
