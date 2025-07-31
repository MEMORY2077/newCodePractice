#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool us2sort(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        if(k==1){
            int ans=0;
            for(int i=0;i<n;i++){
                ans=max(ans,events[i][2]);
            }
            return ans;
        }
        sort(events.begin(),events.end(),us2sort);
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<n;i++){
            int p=bnsearch(events,events[i][0],i);
            for(int j=1;j<=k;j++){
                if(p>=0)dp[i+1][j]=max(dp[i][j],dp[p][j-1]+events[i][2]);
                else dp[i+1][j]=max(dp[i][j],events[i][2]);
            }
        }
        return dp[n][k];
    }
    int bnsearch(vector<vector<int>>& events,int when,int length){
        if(length<0)return-1;
        int left=0;
        int right=length-1;
        int ans=-1;
        while(left<=right){
            int mid=(right-left)/2+left;
            if(events[mid][1]<=when){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};