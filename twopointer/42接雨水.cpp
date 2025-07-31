#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int left=0;
        int right=0;
        int lmax=0;
        int rmax=0;
        while(left<right){
            lmax=max(height[left],lmax);
            rmax=max(height[right],rmax);
            if(lmax<rmax){
                ans+=(lmax-height[left]);
                left++;
            }
            else{
                ans+=(rmax-height[right]);
                right--;
            }
        }
        return ans;
    }
};