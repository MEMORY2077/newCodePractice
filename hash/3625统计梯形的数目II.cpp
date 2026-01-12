#include <vector>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <cfloat>
using namespace std;
class Solution {
    public:
        int countTrapezoids(vector<vector<int>>& points) {
            unordered_map<double,map<double,int>>cnt;//斜率 截距 个数
            unordered_map<int,map<double,int>>cnt2;//中点 斜率 个数
            int n=points.size();
            for(int i=0;i<n;i++){
                int x=points[i][0];
                int y=points[i][1];
                for(int j=i+1;j<n;j++){
                    int x2=points[j][0];
                    int y2=points[j][1];
                    int dy=y-y2;
                    int dx=x-x2;
                    double k=dx?(1.0*dy/dx):DBL_MAX;
                    double b=dx?(1.0*(y*dx-x*dy)/dx):x;
                    cnt[k][b]++;
                    int mid=(x+x2+2000)<<16|(y+y2+2000);
                    cnt2[mid][k]++;
                }
            }
            int ans=0;
            for(auto [_,m]:cnt){
                int s=0;
                for(auto [_,c]:m){
                    ans+=s*c;
                    s+=c;
                }
            }
            for(auto [_,m]:cnt2){
                int s=0;
                for(auto [_,c]:m){
                    ans-=s*c;
                    s+=c;
                }
            }
            return ans;
        }
    };