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
        vector<int>length(n+2,0);
        length[0]=0;
        for(int i=1;i<n;i++){
            freeTime[i]=startTime[i]-endTime[i-1];
            length[i]=freeTime[i-1]+length[i-1];
        }
        length[n]=freeTime[n-1]+length[n-1];
        length[n+1]=freeTime[n]+length[n];
        int result=0;
        for(int i=0;i<=n-k;i++){
            int j=i+k;
            result=max(result,length[j+1]-length[i]);
        }
        return result;
    }
};