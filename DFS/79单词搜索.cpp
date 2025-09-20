#include <vector>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            vector<vector<bool>>visited(n,vector<bool>(m,false));
            auto add=q.front();
            q.pop();
            visited[add.first][add.second]=true;
            if(dfs(board,visited,word,0,add))return true;
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>&visited,string word,int now,pair<int,int> add){
        int n=board.size();
        int m=board[0].size();
        int x=add.first;
        int y=add.second;
        //if(now==word.size()-1&&board[x][y]==word[now])return true;
        if(board[x][y]!=word[now])return false;
        if(now+1==word.size())return true;
        int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<4;i++){
            int nx=x+next[i][0];
            int ny=y+next[i][1];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!visited[nx][ny]){
                visited[nx][ny]=true;
                if(dfs(board,visited,word,now+1,{nx,ny})){
                    return true;
                }
                visited[nx][ny]=false;
            }
        }
        return false;
    }
};