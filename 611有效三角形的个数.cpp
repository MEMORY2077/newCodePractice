#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;;
         int n=nums.size();
        for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                int sum=nums[i]+nums[j];
                int a=binarysearch(nums,sum,j);
                count+=(a-j);
             }
        }   
        return count;
    }
    int binarysearch(vector<int>&nums,int target,int j){
        int left=j+1;
        int right=nums.size()-1;
        int mid=(right-left)/2+left;
        int ans=j;
        while(left<=right){
            mid=(right-left)/2+left;
            if(nums[mid]>=target){
                right=mid-1;
            }
            else{
                ans=mid;
                left=mid+1;
            }
        }
        return ans;
    }
};