#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();
            for(int i=0;i<n;){
                if(i==n-1)return true;
                if(nums[i]==0)return false;
                int maxStep=nums[i];
                if(i+maxStep>=n-1)return true;
                int next=0;
                for(int j=1;j<=maxStep;j++){
                    next=max(next,nums[i+j]);
                }
                i+=next;
            }
            return true;
        }
    };