#include <vector>
#include <algorithm>
#include <set>
#include <limits.h>
using std::vector,std::sort,std::set,std::max,std::min;
class Solution {
    public:
        int maxDistinctElements(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            int ans=0;
            int pre=INT_MIN;
            for(int num:nums){
                int now=min(max(num-k,pre+1),num+k);
                if(now>pre){
                    ans++;
                    pre=now;
                }
            }
            return ans;
        }
    };