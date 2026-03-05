#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        set<pair<long long,int>>pairs;
        int dec=0;
        for(int i=0;i+1<n;i++){
            int x=nums[i];
            int y=nums[i+1];
            if(x>y){
                dec++;
            }
            pairs.emplace(x+y,i);
        }
        set<int>idx;//剩余下标
        for(int i=0;i<n;i++){
            idx.insert(i);
        }
        vector<long long>a(nums.begin(),nums.end());
        int ans=0;
        while(dec>0){
            ans++;
            auto [s,i]=*pairs.begin();
            pairs.erase(pairs.begin());
            auto it = idx.lower_bound(i);
            auto nxt_it=next(it);
            int nxt=*nxt_it;
            dec-=a[i]>a[nxt];//旧数据
            if(it!=idx.begin()){
                int pre=*prev(it);
                dec-=a[pre]>a[i];//旧数据
                dec+=a[pre]>s;//新数据
                pairs.erase({a[pre]+a[i],pre});
                pairs.emplace(a[pre]+s,pre);
            }
            //下一个数，下下个数
            auto nxt2_it=next(nxt_it);
            if(nxt2_it!=idx.end()){
                int nxt2=*nxt2_it;
                dec-=a[nxt]>a[nxt2];//旧的
                dec+=s>a[nxt2];//新的
                pairs.erase({a[nxt]+a[nxt2,nxt],nxt});
                pairs.emplace(s+a[nxt2],i);
            }
            a[i]=s;
            idx.erase(nxt);
        }
        return ans;
    }
};