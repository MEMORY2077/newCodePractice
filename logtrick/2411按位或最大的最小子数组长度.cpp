#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int x=nums[i];
            ans[i]=1;
            for(int j=i-1;j>=0;j--){
                if((nums[j]|x)==nums[j])break;
                nums[j]|=x;
                ans[j]=i-j+1;
            }
        }
        return ans;
    }
};