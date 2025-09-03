#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums) {
            int n=nums.size();
            int cur_right=0;
            int next_right=0;
            int ans=0;
            for(int i=0;i<n-1;i++){
                next_right=max(next_right,i+nums[i]);
                if(i==cur_right){
                    ans++;
                    cur_right=next_right;
                }
            }
            return ans;
        }
    };