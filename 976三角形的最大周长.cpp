#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int largestPerimeter(vector<int>& nums) {
            sort(nums.begin(),nums.end(),us2sort);
            int n=nums.size();
            /*for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        if(nums[k]+nums[j]>nums[i])return nums[i]+nums[j]+nums[k];
                    }
                }
            }*/
            for(int i=0;i<n-2;i++){
                if(nums[i+2]+nums[i+1]>nums[i])return nums[i]+nums[i+1]+nums[i+2];
            }
            return 0;
        }
        static bool us2sort(int &a,int &b){
            return a>b;
        }
    };