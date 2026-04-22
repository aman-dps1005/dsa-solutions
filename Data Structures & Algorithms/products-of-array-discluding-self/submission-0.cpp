class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long totalProduct=1;
        bool isZeroPresent=false;
        bool isMultipleZero=false;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums.at(i)==0){
                if(isZeroPresent){
                    isMultipleZero=true;
                }
                else{
                    isZeroPresent=true;
                }
            }
            else{
                totalProduct*=nums.at(i);
            }
        }

        vector<int> ans=vector<int>(n);
        for(int i=0;i<n;i++){
            if(isZeroPresent){
                if(isMultipleZero){
                    ans[i]=0;
                }
                else if(nums[i]==0){
                    ans[i]=totalProduct;
                }
                else{
                    ans[i]=0;
                }
            }
            else{
                ans[i]=totalProduct/nums[i];
            }
        }

        return ans;
    }
};
