#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>>pre2d;
    int query(int x1,int y1,int x2,int y2){
        int res=pre2d[x2+1][y2+1]-pre2d[x2+1][y2]-pre2d[x2][y2-1]+pre2d[x1][y1];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        pre2d=vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre2d[i+1][j+1]=pre2d[i+1][j]+pre2d[i][j+1]-pre2d[i][j]+mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                while(i+ans<m&&j+ans<n&&query(i,j,i+ans,j+ans)<=threshold){
                    ans++;
                }
            }
        }
        return ans;
    }
};