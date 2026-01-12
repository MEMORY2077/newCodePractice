#include <vector>
using namespace std;
class Solution {
    public:
        const int MOD=1000000007;
        int countPermutations(vector<int>& complexity) {
            int comp0=complexity[0];
            int ans=1;
            int n=complexity.size();
            for(int i=1;i<n;i++){
                if(comp0>=complexity[i])return 0;
                ans=(ans*i)%MOD;
            }
            return ans;
        }
    };