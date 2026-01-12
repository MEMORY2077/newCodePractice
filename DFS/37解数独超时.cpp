#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
    public:
        //queue<pair<int,int>>waitP;
        void solveSudoku(vector<vector<char>>& board) {
            //return;
            //for(int i=0;i<9;i++){
            //    for(int j=0;j<9;j++){
            //        if(board[i][j]=='.')waitP.push({i,j});
            //    }
            //}
            dfs(board,0,0);
        }
        bool dfs(vector<vector<char>>&board,int x,int y){
            if(!test(board,x,y)){
                return false;
            }
            if(x==8&&y==8){
                return true;
            }
            //cout<<1<<endl;
            int ny=y;
            int nx=x;
            while(nx<9&&board[nx][ny]!='.'){
                ny++;
                if(ny==9){
                    ny=0;
                    nx++;
                }
            }
            if(nx==9){
                return true;
                //return false;
            }
            for(int i=1;i<=9;i++){
                board[nx][ny]='0'+i;
                if(dfs(board,nx,ny)){
                    return true;
                }
            }
            board[nx][ny]='.';
            return false;
        }
        bool test(vector<vector<char>>& board,int x,int y){
            unordered_set<char>Hash1;
            unordered_set<char>Hash2;
            for(int i=0;i<9;i++){
                if(board[x][i]=='.')continue;
                if(Hash1.find(board[x][i])!=Hash1.end())return false;
                Hash1.emplace(board[x][i]);
            }
            for(int i=0;i<9;i++){
                if(board[i][y]=='.')continue;
                if(Hash2.find(board[i][y])!=Hash2.end())return false;
                Hash2.emplace(board[i][y]);
            }            
            int stx=(x/3)*3;
            int sty=(y/3)*3;
            unordered_set<char>Hash3;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[stx+i][sty+j]=='.')continue;
                    if(Hash3.find(board[stx+i][sty+j])!=Hash3.end())return false;
                    Hash3.emplace(board[stx+i][sty+j]);                    
                }
            }
            return true;
        }
    };