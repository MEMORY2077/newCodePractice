#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool us2sort(const vector<int>&A,const vector<int>&B){
    if(A[1]<B[1])return true;
    else if(A[1]==B[1])return A[0]<B[0];
    return false;
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),us2sort);
        int Maxday=events[events.size()-1][1];
        vector<int>day(Maxday+1,0);
        int count=0;
        //cout<<"maxday:"<<Maxday<<endl;
        for(auto i:events){
            int now=i[0];
            while(now<=Maxday&&day[now]!=0){
                now++;
                }
            if(now<=Maxday&&now<=i[1]){
                day[now]=1;
                count++;
            }
        }
        return count;
    }
};