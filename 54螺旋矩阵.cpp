#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int circle=(matrix.size()+1)/2;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans(n*m,0);
        int now=0;
        for(int _=0;_<circle;_++){
            for(int i=_;i<=m-_-1;i++){
                if(now==n*m)break;
                ans[now]=matrix[_][i];
                cout<<ans[now]<<' ';
                now++;
            }
            
            for(int i=_+1;i<=n-1-_;i++){
                if(now==n*m)break;
                ans[now]=matrix[i][m-_-1];
                cout<<ans[now]<<' ';
                now++;
            }
            for(int i=m-_-2;i>=_;i--){
                if(now==n*m)break;
                ans[now]=matrix[n-_-1][i];
                cout<<ans[now]<<' ';
                now++;
            }
            for(int i=n-_-2;i>=_+1;i--){
                if(now==n*m)break;
                ans[now]=matrix[i][_];
                cout<<ans[now]<<' ';
                now++;
            }
        }
        return ans;
    }
};