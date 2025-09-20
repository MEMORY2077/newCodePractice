#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    static const int MOD=1000000007;
    vector<int>pp;
    int numberOfWays(int n, int x) {
        pp=vector<int>(n+1,0);
        for(int i=0;i<=n;i++){
            pp[i]=(long long)pow(i,x)%MOD;
        }
        dfs(n,1,n);
        return ans;
    }
    int ans;
    void dfs(int target,int now,int ma){
        if(target<0){
            return;
        }
        if(target==0){
            ans=(ans+1)%MOD;
            return;
        }
        for(int i=now;i<=ma;i++){
            if(pp[i]>target)return;
            dfs(target-pp[i],i+1,ma);
        }
        return;
    }
};