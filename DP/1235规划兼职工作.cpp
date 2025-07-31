#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
bool us2sort(array<int,3>&a,array<int,3>&b){
    if(a[1]<b[1])return true;
    else if(a[1]==b[1])return a[0]<b[0];
    return false;
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<array<int,3>>jobs(n);
        for(int i=0;i<n;i++){
            jobs[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end(),us2sort);
        //for(int i=0;i<n;i++){
        //   cout<<jobs[i][0]<<' '<<jobs[i][1]<<' '<<jobs[i][2]<<endl;
        //}
        vector<int>dp(n+1);
        for(int i=0;i<n;i++){
            int j=bnsearch(jobs,jobs[i][0]-1,i);
           //cout<<"done"<<endl;
            int maxpre=(j>=0)?dp[j+1]:0;
            dp[i+1]=max(dp[i],maxpre+jobs[i][2]);
        }
        return dp[n];
    }
    int bnsearch(vector<array<int,3>>&jobs,int when,int length){
        if(length<0)return -1;
        int left=0;
        int right=length-1;
        int res=-1;
        while(left<=right){
            int mid=(right-left)/2+left;
           // cout<<left<<' '<<right<<' '<<mid<<endl;
            if(jobs[mid][1]<=when){
                left=mid+1;
                res=mid;
                continue;
            }
            right=mid-1;
        }
        return res;
    }
};