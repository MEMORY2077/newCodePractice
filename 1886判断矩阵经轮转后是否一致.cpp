#include <vector>
//初步认为可以三个模拟？
using namespace std;
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //90度
        int n=mat.size();
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]){
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }
        if(flag)return true;
        flag=true;
        for(int i=0,j=n-1;i<n&&j>=0;i++,j--){
            for(int k=0;k<n;k++){
                if(mat[i][k]!=target[k][j]){
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }
        if(flag)return true;
        //270度
        flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[n-j-1][i]){
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }
        if(flag)return true;
        flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[n-i-1][n-j-1])return false;
            }
        }
        return true;
    }
};