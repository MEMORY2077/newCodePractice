#include <vector>
using std::vector;
class Solution {
    public:
        bool hasIncreasingSubarrays(vector<int>& nums, int k) {
            int n=nums.size();
            for(int _=0;_+k<n;_++){
                int a=_;
                int b=a+k;
                if(b+k>n)return false;
                bool flag1=true;
                bool flag2=true;
                for(int i=1;i<k;i++){
                    if(nums[a+i]<=nums[a+i-1]){
                        flag1=false;
                        break;
                    }
                    if(nums[b+i]<=nums[b+i-1]){
                        flag2=false;
                        break;
                    }
                }
                if(flag1&&flag2)return true;
            }
            return false;
        }
    };