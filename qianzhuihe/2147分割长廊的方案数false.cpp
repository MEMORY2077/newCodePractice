#include <string>
#include <vector>
//可以插任意数量，不是只能插一个
using namespace std;
class Solution {
    public:
        int numberOfWays(string corridor) {
            int n=corridor.size();
            vector<int>pre(n+1,0);
            long long ans=0;
            for(int i=1;i<=n;i++){
                pre[i]=pre[i-1]+(corridor[i-1]=='S');
            }
            int sum=pre[n];
            if(sum==2)ans++;
            for(int i=0;i<=n;i++){
                //cout<<pre[i]<<' ';
                if(pre[i]>=2&&(sum-pre[i]>=2))ans++;
            }
            return ans%1000000007;
        }
    };