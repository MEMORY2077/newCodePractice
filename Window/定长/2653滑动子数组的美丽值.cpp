#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        map<int,int>hav;
        vector<int>ans(n-k+1);
        for(int i=0;i<n;i++){
            hav[nums[i]]++;
            int l=i-k+1;
            if(l<0)continue;
            int cnt=0;
            for(auto[now,c]:hav){
                //cout<<now<<' '<<c<<endl;
                if(cnt+c>=x){
                    ans[i-k+1]=min(now,0);
                    //if(now<0)cout<<now<<endl;
                    break;
                }
                cnt+=c;
            }
            hav[nums[l]]--;
        }
        return ans;
    }
};