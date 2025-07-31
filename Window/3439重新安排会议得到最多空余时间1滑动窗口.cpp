#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freeTime(n+1,0);
        freeTime[0]=startTime[0];
        freeTime[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++){
            freeTime[i]=startTime[i]-endTime[i-1];
        }
        int result=0;
        int sum=0;
        for(int i=0;i<=min(k,n);i++){
            sum+=freeTime[i];
        }
        result=sum;
        for(int i=1;i<=n-k;i++){
            sum=sum-freeTime[i-1]+freeTime[i+k];
            result=max(sum,result);
        }
        return result;
    }
};