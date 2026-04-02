#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int>od;
        int M=grid.size();
        int N=grid[0].size();
        for(auto x:grid){
            od.insert(od.end(),x.begin(),x.end());
        }
        int n=od.size();
        vector<unsigned long long>pre(n+1,1);
        vector<unsigned long long>last(n+1,1);
        int MOD=12345;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]*od[i-1]%MOD;
            last[n-i]=last[n-i+1]*od[n-i]%MOD;
        }
        vector<vector<int>>ans(M,vector<int>(N,0));
        for(int i=0;i<n;i++){
            ans[i/N][i%N]=pre[i]*last[i+1]%MOD;
        }
        return ans;
    }
};