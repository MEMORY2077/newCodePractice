#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int r=height.size()-1;
        int l=0;
        int ans=(r-l+1)*min(height[r],height[l]);
        while(l<r){
            if(height[r]<height[l]){
                r--;
            }
            else l++;
            ans=max(ans,(r-l+1)*min(height[r],height[l]));
        }
        return ans;
    }
};