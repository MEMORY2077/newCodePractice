#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            vector<vector<int>>minimum(n+1,vector<int>(2,0x3f3f3f3f));
            vector<vector<int>>maximum(n+1,vector<int>(2,-1));
            for(auto building:buildings){
                int x=building[0];
                int y=building[1];
                minimum[y][0]=min(minimum[y][0],x);
                maximum[y][0]=max(maximum[y][0],x);
                minimum[x][1]=min(minimum[x][1],y);
                maximum[x][1]=max(maximum[x][1],y);
            }
            int ans=0;
            for(auto building:buildings){
                int x=building[0];
                int y=building[1];
                if(minimum[y][0]<x&&maximum[y][0]>x&&minimum[x][1]<y&&maximum[x][1]>y){
                    ans++;
                }
            }
            return ans;
        }
    };