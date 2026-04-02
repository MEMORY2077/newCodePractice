#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>pre(n,0);
        vector<int>last(n,0);
        pre[0]=height[0];
        last[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
            last[n-1-i]=max(last[n-i],height[n-1-i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max((min(pre[i],last[i])-height[i]),0);
        }
        return ans;
    }
};