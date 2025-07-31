#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freeTime(n+1,0);
        freeTime[0]=startTime[0];
        for(int i=1;i<n;i++){
            freeTime[i]=startTime[i]-endTime[i-1];
        }
        freeTime[n]=eventTime-endTime[n-1];
        int a=0;
        int b=-1;
        int c=-1;
        for(int i=1;i<=n;i++){
            if(freeTime[i]>freeTime[a]){
                //别忘了世袭
                c=b;
                b=a;
                a=i;
            }
            else{
                if(b<0||freeTime[i]>freeTime[b]){
                    c=b;
                    b=i;
                }
                else{
                    if(c<0||freeTime[i]>freeTime[c]){
                        c=i;
                    }
                }
            }
        }
        int result=0;
        for(int i=0;i<n;i++){//这个枚举思路应该体会一下
            int now=endTime[i]-startTime[i];
            if((i!=a&&i+1!=a&&now<=freeTime[a])||(i!=b&&i+1!=b&&now<=freeTime[b])||(now<=freeTime[c])){
                result=max(result,freeTime[i]+freeTime[i+1]+now);
            }
            else{
                result=max(result,freeTime[i]+freeTime[i+1]);
            }
        }
        return result;
    }
};