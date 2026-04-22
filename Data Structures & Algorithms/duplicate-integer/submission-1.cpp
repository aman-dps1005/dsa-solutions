class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> presence;
        for(int it:nums){
            if(presence.find(it)!= presence.end()){
                return true;
            }
            presence.insert(it);
        }

        return false;
    }
};