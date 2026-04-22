class Solution {
public:
    int solve(int ind,vector<int>& prices,int size,bool canBuy){
        if(ind==size){
            return 0;
        }

        int soln;
        if(canBuy){
            soln=max(solve(ind+1,prices,size,canBuy),-prices[ind]+solve(ind+1,prices,size,!canBuy));
        }
        else{
            soln=max(solve(ind+1,prices,size,canBuy),prices[ind]);
        }
        return soln;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        return solve(0,prices,n,true);
    }
};
