#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>res(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                vector<int>a;
                int ans=0x3f3f3f3f;
                for(int l=0;l<k;l++){
                    for(int r=0;r<k;r++){
                        a.push_back(grid[i+l][j+r]);
                    }
                }
                sort(a.begin(),a.end());
                for(int l=1;l<a.size();l++){
                    if(a[l-1]<a[l]){
                        ans=min(ans,a[l]-a[l-1]);
                    }
                }
                if(ans<0x3f3f3f3f)res[i][j]=ans;
            }
        }
        return res;
    }
};