class Solution {
public:
    int solve(int ind,vector<int>& prices,int size,bool canBuy,vector<vector<int>>&dp){
        if(ind==size){
            return 0;
        }
        if(dp[ind][canBuy]!=0) return dp[ind][canBuy];
        int soln;
        if(canBuy){
            dp[ind][canBuy]=max(solve(ind+1,prices,size,canBuy,dp),-prices[ind]+solve(ind+1,prices,size,!canBuy,dp));
        }
        else{
            dp[ind][canBuy]=max(solve(ind+1,prices,size,canBuy,dp),prices[ind]);
        }
        return dp[ind][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        return solve(0,prices,n,true,dp);
    }
};
