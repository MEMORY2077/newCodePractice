#include <vector>
#include <string>
#include <bit>
using namespace std;
class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        const int MOD=1000000007;
        
        for(int i=1;i<=n;i++){
            int a=__bit_width((unsigned int)i);
            ans<<=a;
            ans|=i;
            ans%=MOD;
        }
        return ans;
    }
};