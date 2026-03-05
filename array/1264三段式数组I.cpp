#include <vector>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int mode=0;
        bool up=true;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])return false;
            if(up&&nums[i]<nums[i-1]){
                if(mode==2)return false;
                up=false;
                mode++;
                continue;
            }
            if(!up&&nums[i]>nums[i-1]){
                up==true;
                mode++;
                continue;
            }
        }
        if(mode!=2)return false;
        return true;
    }
};