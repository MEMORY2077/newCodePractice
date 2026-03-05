#include <vector>
using namespace std;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>maxRight(n+1,0);
        for(int i=0;i<=n;i++){
            int left=max(i-ranges[i],0);
            maxRight[left]=max(maxRight[left],i+ranges[i]);
        }
        int ans=0;
        int maxr=0;
        int curr=0;
        for(int i=0;i<n;i++){
            maxr=max(maxr,maxRight[i]);
            if(i==curr){
                if(i==maxr)return -1;
                curr=maxr;
                ans++;
            }
        }
        return ans;
    }
};