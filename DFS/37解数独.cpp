#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
class Solution {
    public:
        bool row[9][9]={{false}};
        bool col[9][9]={{false}};
        bool gong[3][3][9]={{false}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>nextP;
        int waitcount(vector<vector<char>>&board,int x,int y){
            int result=9;
            for(int i=0;i<9;i++){
                if(row[x][i]||col[y][i]||gong[x/3][y/3][i]){
                    result--;
                }
            }
            return result;
        }
        void solveSudoku(vector<vector<char>>& board) {
            vector<pair<int,int>>w;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(board[i][j]!='.'){
                        int now=board[i][j]-'1';
                        row[i][now]=col[j][now]=gong[i/3][j/3][now]=true;
                    }
                    else{
                        w.push_back({i,j});
                    }
                }
            }
            for(auto [i,j]:w){
                nextP.push({waitcount(board,i,j),i,j});
            }
            dfs(board);
        }
        bool dfs(vector<vector<char>>&board){
            if(nextP.empty()){
                return true;
            }
            auto [_,x,y]=nextP.top();
            nextP.pop();
            int waitn=0;
            for(int i=0;i<9;i++){
                if(row[x][i]||col[y][i]||gong[x/3][y/3][i]){
                    continue;
                }
                board[x][y]='1'+i;
                row[x][i]=col[y][i]=gong[x/3][y/3][i]=true;
                if(dfs(board)){
                    return true;
                }
                row[x][i]=col[y][i]=gong[x/3][y/3][i]=false;
                waitn++;
            }
            nextP.push({waitn,x,y});
            return false;
        }
    };