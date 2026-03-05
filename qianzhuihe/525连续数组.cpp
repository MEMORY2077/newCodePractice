#include<vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int &x:nums){
            x=x?1:-1;
        }
        int n=nums.size();
        vector<int>sum(n+1);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        unordered_map<int,int>pos;
        int ans=0;
        for(int i=0;i<=n;i++){
            int s=sum[i];
            if(pos.find(s)!=pos.end())ans=max(ans,i-pos[s]);
            else pos[s]=i;
        }
        return ans;
    }
};