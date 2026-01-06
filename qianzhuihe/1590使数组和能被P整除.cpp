#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int minSubarray(vector<int>& nums, int p) {
            int n=nums.size();
            vector<int>pre(n+1,0);
            vector<int>last(n+1,0);
            unordered_map<int,set<int>>l;
            for(int i=0;i<n;i++){
                pre[i+1]=(pre[i]+nums[i])%p;
            }
            l[0].emplace(n);
            for(int i=n-1;i>=0;i--){
                last[i]=(last[i+1]+nums[i])%p;
                //last[n]=0,last[n-1l]
                l[last[i]].emplace(i);
            }
            //if(last[0]%p==0)return 0;
            int length=0x3f3f3f3f;
            for(int left=0;left<=n;left++){
                int pl=pre[left];
                int pr=(2*p-pl)%p;
                auto it=l[pr].lower_bound(left);
                if(it!=l[pr].end())length=min(length,*it-left);
            }
            if(length==0x3f3f3f3f||length==n)return -1;
            return length;
        }
    };