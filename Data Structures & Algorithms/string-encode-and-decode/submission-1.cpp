class Solution {
public:
    char delimiter='#';
    string encode(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs.size();i++){
            int len=strs.at(i).length();
            ans+=to_string(len)+delimiter+strs.at(i);
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string>strs;
        int len=s.length();
        int i=0;
        while(i<len){
            int j=i;
            while(s.at(j)!=delimiter){
                j++;
            }
            string num=s.substr(i,j-i);
            int nmber=stoi(num);
            i=j+1;
            strs.push_back(s.substr(i,nmber));
            i=i+nmber;
        }

        return strs;
    }
};
