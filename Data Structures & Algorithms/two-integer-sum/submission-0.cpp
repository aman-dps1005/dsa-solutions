class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> count;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count.find(target-nums.at(i))!=count.end()){
                return {count[target-nums.at(i)],i};
            }

            count[nums[i]]=i;
        }

        return ans;
    }
};
