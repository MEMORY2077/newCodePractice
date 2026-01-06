#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
    public:
        unordered_set<int>d;
        vector<int>MEMORY;
        vector<int>costs;
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            MEMORY=vector<int>(366,-1);
            this->costs=costs;
            for(int day:days){
                d.emplace(day);
            }
            return dp(1);
        }
        int dp(int now){
            if(now>365)return 0;
            if(MEMORY[now]!=-1)return MEMORY[now];
            if(d.count(now)){
                MEMORY[now]=min({dp(now+1)+costs[0],dp(now+7)+costs[1],dp(now+30)+costs[2]});
            }
            else MEMORY[now]=dp(now+1);
            return MEMORY[now];
        }
    };