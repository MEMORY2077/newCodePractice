#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
            int n=prices.size();
            vector<long long>pre(n+1,0);
            for(int i=1;i<=n;i++){
                pre[i]=pre[i-1]+(strategy[i-1]*prices[i-1]);
            }
            long long ans=pre[n];
            for(int i=0;i+k<=n;i++){
                //0 1 2 3 4 5
                long long now=pre[n];
                now-=(pre[i+k]-pre[i]);
                for(int kk=k/2;kk<k;kk++){
                    now+=prices[i+1+kk];
                }
                ans=max(ans,now);
            }
            return ans;
        }
    };