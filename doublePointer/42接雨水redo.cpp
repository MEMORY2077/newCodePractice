#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int left=0;
        int right=n-1;
        int max_left=0;
        int max_right=0;
        for(int i=0;i<n;i++){
            max_left=max(height[left],max_left);
            max_right=max(height[right],max_right);
            ans+=max(min(max_left,max_right)-height[i],0);
            if(max_left>max_right)left++;
            else right--;
        }
        return ans;
    }
};