//前缀和，找到k=s[i]-s[j]
//s[j]==s[i]-k
//稍微变化一下就能看出来这又是一个两数之和问题
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
            cout<<pre[i]<<' ';
        }
        cout<<endl;
        unordered_map<int,int>map;
        int ans=0;
        for(int i=0;i<=n;i++){
            auto now=map.find(pre[i]-k);
            if(now==map.end())map[pre[i]]++;
            else {
                ans+=now->second;
                map[pre[i]]++;
                //先更新ans，后更新cnt
                //否则在k=0时会出错，会把 自己-自己加进去？
                }
        }
        for(auto i:map){
            cout<<i.first<<' '<<i.second<<endl;
        }
        return ans;
    }
};