#include <vector>
using namespace std;
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int ans=0;
        int res=0;
        int n=prizePositions.size();
        int l=0;
        for(int i=0;i<n;i++){
            res++;
            while(prizePositions[i]-prizePositions[l]+1>k){
                res--;
                l++;
            }
            if(prizePositions[i]-prizePositions[l]+1==k)ans=max(ans,res);
        }
        return ans;
    }
};