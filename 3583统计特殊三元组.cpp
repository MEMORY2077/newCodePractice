#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    public:
        const int MOD=1000000007;
        int specialTriplets(vector<int>& nums) {
            unordered_map<int,int>cnt1;
            unordered_map<int,long long>cnt12;
            long long cnt123=0;
            for(int x:nums){
                if(x%2==0){
                    cnt123+=cnt12[x/2];
                }
                cnt12[x]+=cnt1[x*2];
                cnt1[x]++;
            }
            return cnt123%MOD;
        }
    };