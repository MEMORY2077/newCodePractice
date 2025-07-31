#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>pre(n);
        vector<int>last(n);
        pre[0]=height[0];
        //cout<<pre[0]<<endl;
        last[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
            last[n-i-1]=max(last[n-i],height[n-i-1]);
        }
        //for(int i=0;i<n;i++){
        //    cout<<pre[i]<<' ';
            //last[n-i-1]=max(pre[n-i],height[n-i-1]);
        //}
        cout<<endl;
        //for(int i=0;i<n;i++){
        //    cout<<last[i]<<' ';
        //}
        //cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(pre[i],last[i])-height[i]);
        }
        return ans;
    }
};