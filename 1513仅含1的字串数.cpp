#include <string>
#include <vector>
using namespace std;
class Solution {
    const int MOD=1000000007;
    public:
        int numSub(string s) {
            vector<int>z;
            s.push_back('0');
            int n=s.size();
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    z.push_back(i);
                }
            }
            int nz=z.size();
            int ans=0;
            for(int i=0;i<nz;i++){
                if(i==0){
                    int now=((z[i]+1)*z[i]/2)%MOD;
                    ans=(ans+now)%MOD;
                }
                else{
                    int count=z[i]-z[i-1]-1;
                    int now=((long long)(count+1)%MOD*count/2%MOD)%MOD;
                    ans=(ans+now)%MOD;
                }
            }
            return ans;
        }
    };