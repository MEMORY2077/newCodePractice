#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        static bool us2sort(const vector<int>&points1,const vector<int>&points2){
            if(points1[0]<points2[0])return true;
            return points1[1]>points2[1];
        }
        int numberOfPairs(vector<vector<int>>& points) {
            int ans=0;
            int n=points.size();
            sort(points.begin(),points.end(),us2sort);
            for(int i=0;i<n;i++){
                int maximum=0;
                for(int j=i+1;j<n;j++){
                    if(points[j][1]<=maximum)continue;
                    ans++;
                    maximum=max(maximum,points[j][1]);
                }
            }
            return ans;
        }
    };