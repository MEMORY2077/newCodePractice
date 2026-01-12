#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        double largestTriangleArea(vector<vector<int>>& points) {
            double maximum=INT_MIN;
            int n=points.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        double x1=points[i][0]-points[j][0];
                        double y1=points[i][1]-points[j][1];
                        double x2=points[i][0]-points[k][0];
                        double y2=points[i][1]-points[k][1];
                        maximum=max(abs(x1*y2-x2*y1)/2,maximum);
                    }
                }
            }
            return maximum;
        }
    };