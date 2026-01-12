#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int intersectionSizeTwo(vector<vector<int>>& intervals) {
            int n=intervals.size();
            int ans=2*n;
            sort(intervals.begin(),intervals.end());
            for(int i=1;i<n;i++){
                if(intervals[i][0]<=intervals[i-1][1]){
                    int cha=intervals[i-1][1]-intervals[i][0]+1;
                    if(cha>=2)ans-=2;
                    else ans-=cha;
                }
            }
            return ans;
        }
    };