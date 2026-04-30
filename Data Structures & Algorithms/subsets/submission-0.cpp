class Solution {
public:
    void solve(int ind,int n,vector<int>&nums,vector<vector<int>>&ans,vector<int>& tempStore){
        if(ind>=n){
            ans.push_back(tempStore);
            return;
        }

        tempStore.push_back(nums[ind]);
        solve(ind+1,n,nums,ans,tempStore);
        tempStore.pop_back();
        solve(ind+1,n,nums,ans,tempStore);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> tempStore;
        int n=nums.size();
        solve(0,n,nums,ans,tempStore);

        return ans;
    }
};
