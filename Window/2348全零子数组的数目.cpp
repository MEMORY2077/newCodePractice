#include <vector>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        for(int now:nums){
            if(now==0){
                cnt++;
                continue;
            }
            if(now!=0){
                if(cnt==0)continue;
                else{
                    ans+=((cnt+1)*cnt/2);
                    cnt=0;
                    continue;
                }
            }
        }
        if(cnt!=0){
            ans+=((cnt+1)*cnt/2);
            cnt=0;
        }
        return ans;
    }
};