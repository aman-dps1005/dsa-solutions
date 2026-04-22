#include<bits/stdc++.h>
class Solution {
public:
    bool isPossible(vector<int>& piles,int h,int k){
        int n=piles.size();
        int totalTime=0;
        for(int i=0;i<n;i++){
            totalTime+=(piles[i] + k - 1) / k;
        }

        return totalTime<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxRange=INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>maxRange){
                maxRange=piles[i];
            }
        }

        int start=1;
        int end=maxRange;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(isPossible(piles,h,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
};
