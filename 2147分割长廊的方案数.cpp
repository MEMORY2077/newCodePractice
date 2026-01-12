#include <string>
#include <vector>
//可以插任意数量，不是只能插一个
using namespace std;
class Solution {
    public:
        const int MOD=1000000007;
        int numberOfWays(string corridor) {
            int n=corridor.size();
            int last=-1;
            int now=-1;
            int cnt=0;
            int ans=1;
            for(int i=0;i<n;i++){
                if(corridor[i]=='S'){
                    cnt++;
                    last=now;
                    now=i;
                    if(cnt>1&&cnt%2){
                        ans=(ans*(now-last))%MOD;
                    }
                }
            }
            if(cnt%2||cnt==0)return 0;
            return ans;
        }
    };