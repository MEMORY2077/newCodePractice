#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>grid(n,string(n,'.'));
        dfs(grid,0);
        return ans;
    }
    void dfs(vector<string>grid,int now){
        if(now>=grid.size()){
            ans.push_back(grid);
            return;
        }
        int n=grid.size();
        for(int i=0;i<n;i++){
            grid[now][i]='Q';
            if(check(grid,now,i)){
                dfs(grid,now+1);
            }
            grid[now][i]='.';
        }
    }
    bool check(vector<string>&grid,int x,int y){
        for(int i=0;i<x;i++){
            if(grid[i][y]=='Q')return false;
        }
        for(int i=x-1,j=y-1;j>=0&&i>=0;i--,j--){
            if(grid[i][j]=='Q')return false;
        }
        for(int i=x-1,j=y+1;i>=0&&y<grid.size();i--,j++){
            if(grid[i][j]=='Q')return false;
        }
        return true;
    }
    vector<vector<string>>ans;
};