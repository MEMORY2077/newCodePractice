#include <math.h>
class Solution {
    public:
        int countTriples(int n) {
            int c=sqrt(n);
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    int k=i*i+j*j;
                    int sqk=sqrt(k);
                    if(k<=n*n&&(i!=j&&j!=k)&&sqk*sqk==k)ans+=2;
                }
            }
            return ans;
        }
    };