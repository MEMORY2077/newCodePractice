#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            ans=min(ans,abs(k-nums[i]));
            for(int j=i-1;j>=0;j--){
                if((nums[j]|x)==nums[j])break;
                nums[j]|=x;
                ans=min(ans,abs(k-nums[j]));
            }
        }
        return ans;
    }
};