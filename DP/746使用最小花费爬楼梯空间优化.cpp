#include <vector>
using namespace std;
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n=cost.size();
            int a=0;
            int b=0;
            for(int i=2;i<=n;i++){
                int c=min(b+cost[i-1],a+cost[i-2]);
                a=b;
                b=c;
            }
            return b;
        }
    };