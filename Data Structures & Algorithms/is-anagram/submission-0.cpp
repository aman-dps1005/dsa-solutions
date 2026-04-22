class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        int n=s.length();
        unordered_map<char,int> sCount;
        unordered_map<char,int> tCount;
        for(int i=0;i<n;i++){
            sCount[s[i]]++;
            tCount[t[i]]++;
        }

        for(auto it:sCount){
            if(it.second!=tCount[it.first]){
                return false;
            }
        }

        return true;
    }
};
