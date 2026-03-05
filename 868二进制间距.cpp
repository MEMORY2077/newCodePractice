#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int c=0;
        vector<int>w(32,-1);
        for(int i=0;i<32;i++){
            if((n&1)==1){
                w[c]=i;
                c++;
            }
            n>>=1;
        }
        if(c==0||c==1)return 0;
        int ans=-1;
        for(int i=1;i<c;i++){
            ans=max(w[i]-w[i-1],ans);
        }
        return ans;
    }
};