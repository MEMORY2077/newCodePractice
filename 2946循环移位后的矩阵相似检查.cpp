#include <vector>
#include <algorithm>
using namespace std;
//其实原地比较就行，也没要最终矩阵
//if (row[j] != row[(j + k) % n])return false;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        //1 2 3 4 5 6 7
        //4 5 6 7 1 2 3
        //7 6 5 4 3 2 1
        //5 6 7 1 2 3 4左移4
        //
        int m=mat[0].size();
        k=k%m;
        vector<vector<int>>nmat=mat;
        int n=nmat.size();
        int lk=m-k;;
        for(int i=0;i<n;i++){
            reverse(nmat[i].begin(),nmat[i].end());
            if(i%2){
                reverse(nmat[i].begin(),nmat[i].begin()+k);
                reverse(nmat[i].begin()+k,nmat[i].end());
            }
            else{
                reverse(nmat[i].begin(),nmat[i].begin()+lk);
                reverse(nmat[i].begin()+lk,nmat[i].end());
            }
        }
        if(mat==nmat)return true;
        return false;
    }
};