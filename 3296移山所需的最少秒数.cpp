#include <queue>
using namespace std;
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<tuple<long long ,long long ,int>,vector<tuple<long long,long long ,int>>,greater<>>pq;
        for(int t:workerTimes){
            pq.emplace(t,t,t);
        }
        long long ans=0;
        while(mountainHeight--){
            auto [total,cur,base]=pq.top();
            pq.pop();
            pq.emplace(total+cur+base,cur+base,base);
        }
        return ans;
    }
};