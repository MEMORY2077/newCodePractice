#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int res = 0;
        int n = bottomLeft.size();
        for(int i = 0; i < n; i++){
            int bx = bottomLeft[i][0];
            int by = bottomLeft[i][1];
            int tx = topRight[i][0];
            int ty = topRight[i][1];
            for(int j = 0; j < i; j++){
                int bx2 = bottomLeft[j][0];
                int by2 = bottomLeft[j][1];
                int tx2 = topRight[j][0];
                int ty2 = topRight[j][1];
                int width = min(tx,tx2)-max(bx,bx2);
                int weight = min(ty,ty2)-max(by,by2);
                res = max(res,min(width,weight));
            }
        }
        return 1LL*res*res;
    }
};