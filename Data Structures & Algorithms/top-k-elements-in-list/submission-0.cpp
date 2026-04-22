class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> freq(n+1);
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            freq[it.second].push_back(it.first);
        }
        int temp=k;
        vector<int>ans;
        for(int i=n;i>0;i--){
            for(int j=0;j<freq.at(i).size();j++){
                if(temp>0){
                    ans.push_back(freq[i][j]);
                    temp--;
                }
                else{
                    break;
                }
            }
        }

        return ans;
    }
};
