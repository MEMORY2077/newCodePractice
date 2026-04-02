//这种求最短的应该把ans更新放在while循环里🤔
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        int l=0;
        int n=nums.size();
        int ans=0x3f3f3f3f;
        int res=0;
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]]==1)res+=nums[i];
            while(res>=k){
                ans=min(ans,i-l+1);
                cnt[nums[l]]--;
                if(cnt[nums[l]]==0)res-=nums[l];
                l++;
            }
        }
        if(ans>n)return -1;
        return ans;
    }
};