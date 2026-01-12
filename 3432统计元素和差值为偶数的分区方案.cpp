#include <vector>
using namespace std;
class Solution {
    public:
        int countPartitions(vector<int>& nums) {
            int n=nums.size();
            vector<int>pre(n+1,0);
            for(int i=1;i<=n;i++){
                pre[i]=pre[i-1]+nums[i-1];
            }
            int sum=pre[n];
            int ans=0;
            //1,2,2
            //1,3,5
            for(int i=1;i<n;i++){
                //pre[i]-(sum-pre[i])
                //1-(5-1)=-3
                //3-(5-3)=1
                if((pre[i]-(sum-pre[i]))%2==0)ans++;
            }
            return ans;
        }
    };