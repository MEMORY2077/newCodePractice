#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            //横着
            for(int i=0;i<9;i++){
                unordered_set<char>Hash;
                for(int j=0;j<9;j++){
                    if(board[i][j]=='.')continue;
                    if(Hash.find(board[i][j])!=Hash.end())return false;
                    Hash.emplace(board[i][j]);
                }
            }
            //cout<<1<<endl;
            //竖着
            for(int i=0;i<9;i++){
                unordered_set<int>Hash;
                for(int j=0;j<9;j++){
                    if(board[j][i]=='.')continue;
                    if(Hash.find(board[j][i])!=Hash.end())return false;
                    Hash.emplace(board[j][i]);
                }
            }
            //cout<<2<<endl;
            //宫格
            for(int k=0;k<3;k++){
                for(int h=0;h<3;h++){
                    unordered_set<int>Hash;
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            if(board[k*3+i][h*3+j]=='.')continue;
                            if(Hash.find(board[k*3+i][h*3+j])!=Hash.end())return false;
                            Hash.emplace(board[k*3+i][h*3+j]);
                        }
                    }
                }
            }
            return true;
        }
    };