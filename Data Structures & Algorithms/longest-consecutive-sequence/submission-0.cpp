class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int maxLen=1;

        unordered_set<int> st;
        for(int it:nums){
            st.insert(it);
        }

        for(int it:st){
            if(st.find(it-1)==st.end()){//you can start
                int count=1;
                int numb=it;
                while(st.find(numb+1)!=st.end()){
                    count+=1;
                    numb=numb+1;
                }
                maxLen=max(maxLen,count);
            }
        }

        return maxLen;
    }
};
