#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n=s.size();
            vector<int>cz(n+1,0);
            cz[0]=0;
            for(int i=1;i<=n;i++){
                cz[i]=cz[i-1];
                if(s[i-1]=='0')cz[i]++;
            }
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    int z=cz[j+1]-cz[i];
                    //cout<<i<<' '<<j<<' '<<z<<endl;
                    int o=j-i+1-z;
                    if(o>=z*z)ans++;
                }
            }
            return ans;
        }
    };