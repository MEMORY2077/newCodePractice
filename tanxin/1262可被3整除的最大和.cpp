#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        static bool us2sort(int &a,int &b){
            return a>b;
        }
        int maxSumDivThree(vector<int>& nums) {
            int n=nums.size();
            int ans=0;
            vector<vector<int>>sub(3,vector<int>(2,0x3f3f3f3f));
            for(int i=0;i<n;i++){
                ans+=nums[i];
                if(nums[i]<sub[nums[i]%3][0]){
                    sub[nums[i]%3][1]=sub[nums[i]%3][0];
                    sub[nums[i]%3][0]=nums[i];
                }
                else if(nums[i]<sub[nums[i]%3][1]){
                    sub[nums[i]%3][1]=nums[i];
                }
            }
            //if(ans%3==0)return ans;
            //cout<<ans<<endl;
            //cout<<sub[1][0]<<' '<<sub[1][1]<<' '<<sub[2][0]<<' '<<sub[2][1]<<endl;
            if(ans%3==1){
                int s=min({sub[1][0],sub[2][0]+sub[2][1]});
                ans-=s;
            }
            else if(ans%3==2){
                int s=min({sub[2][0],sub[1][0]+sub[1][1]});
                ans-=s;
            }
            return ans;
        }
    };