#include<array>
class Solution {
public:
struct ArrayHash {
    size_t operator()(const array<int,26>& a) const {
        size_t h = 0;
        for (int x : a) {
            h = h * 31 + std::hash<int>()(x);
        }
        return h;
    }
};
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int,26>,vector<string>,ArrayHash>mp;
        int n=strs.size();

        for(int i=0;i<n;i++){
            array<int,26> arr{};
            for(int j=0;j<strs.at(i).length();j++){
                arr[strs.at(i)[j]-'a']++;
            }
            mp[arr].push_back(strs.at(i));
        }

        vector<vector<string>>ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
