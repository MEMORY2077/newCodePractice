#include <vector>
#include <deque>
using namespace std;
class Solution {
    public:
        int countPartitions(vector<int>& nums, int k) {
            const int MOD=1000000007;
            int n=nums.size();
            deque<int>min_q,max_q;
            vector<int>dp(n+1);
            dp[0]=1;
            long long sum_f=0;
            int left=0;
            for(int i=0;i<n;i++){
                int x=nums[i];
                //入
                sum_f+=dp[i];
                while(!min_q.empty()&&x<=nums[min_q.back()]){
                    min_q.pop_back();//右侧pop，拿当前的和右侧比，把比i大的全都踢出去
                }
                min_q.push_back(i);//放右边，进来一个最小，L-i最小的候选者有i了
                while(!max_q.empty()&&x>=nums[max_q.back()]){
                    max_q.pop_back();//同上
                }
                max_q.push_back(i);
                //出
                while(nums[max_q.front()]-nums[min_q.front()]>k){//左侧最大最小
                    sum_f-=dp[left];
                    left++;
                    if(min_q.front()<left){//L++
                        min_q.pop_front();
                    }
                    if(max_q.front()<left){
                        max_q.pop_front();
                    }
                }
                dp[i+1]=sum_f%MOD;
            }
            return dp[n];
        }
    };