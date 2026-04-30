class Solution {
public:
    void solve(int ind,int size,vector<int>&temp,vector<vector<int>>&ans,int target,vector<int>& nums){
        if(ind>=size){
            if(target==0) ans.push_back(temp);
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }


        //include
        if(nums[ind]<=target){
            temp.push_back(nums[ind]);
            solve(ind,size,temp,ans,target-nums[ind],nums);
            temp.pop_back();
            solve(ind+1,size,temp,ans,target,nums);
        }else{
            solve(ind+1,size,temp,ans,target,nums);
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> tempStore;
        solve(0,n,tempStore,ans,target,nums);

        return ans;
    }
};
