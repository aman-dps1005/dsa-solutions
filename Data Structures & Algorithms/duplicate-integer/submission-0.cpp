class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool> presence;
        for(int i=0;i<n;i++){
            if(presence.find(nums.at(i))!= presence.end()){
                return true;
            }
            presence.insert({nums.at(i),true});
        }

        return false;
    }
};