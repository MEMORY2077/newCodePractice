#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
template<>
struct greater<pair<int,int>>{
    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
        if(a.second>b.second)return true;
        else if(a.second==b.second)return a.first>b.first;
        return false;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int Maxday=0;
        for(auto i:events){
            if(i[1]>Maxday)Maxday=i[1];
            pq.push({i[0],i[1]});
        }
        int n=events.size();
        Maxday=min(Maxday,n);
        vector<int>day(Maxday+1,0);
        int count=0;
        //cout<<"maxday:"<<Maxday<<endl;
        while(!pq.empty()){
            auto now=pq.top();
            pq.pop();
            for(int i=now.first;i<=now.second;i++){
                if(day[i]!=0)continue;
                if(day[i]==0){
                    day[i]=1;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};