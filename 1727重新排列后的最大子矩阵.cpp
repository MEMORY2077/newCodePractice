#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<int>cnt1(n,0);
        for(vector<int>row:matrix){
            for(int j=0;j<n;j++){
                int x=row[j];
                if(x==1)cnt1[j]++;
                else cnt1[j]=0;
            }
            sort(cnt1.begin(),cnt1.end());
            for(int i=0;i<n;i++){
                ans=max(ans,cnt1[i]*(n-i));
            }
        }
        return ans;
    }
};
//1 1 0
//1 0 1