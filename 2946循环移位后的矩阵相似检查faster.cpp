#include <vector>
#include <algorithm>
using namespace std;
//其实原地比较就行，也没要最终矩阵
//if (row[j] != row[(j + k) % n])return false;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        for(auto &row:mat){
            for(int j=0;j<n;j++){
                if(row[j]!=row[(j+k)%n])return false;
            }
        }
        return true;
    }
};