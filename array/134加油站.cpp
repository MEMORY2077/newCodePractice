#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //1 3 6 10 15
        //-3 -7 -12 -13 -15
        int n=gas.size();
        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+gas[i-1]-cost[i-1];
            if(pre[i]>=0)return i-1;
        }
    }
};