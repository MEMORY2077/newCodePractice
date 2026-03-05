#include <vector>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool isAscending=false;
        int n=nums.size();
        int count=0;
        while(!isAscending){
            int minindex=0;
            isAscending=true;
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1])isAscending=false;
                if(nums[minindex]+nums[minindex+1]>nums[i]+nums[i+1]){
                    minindex=i;
                }
            }
            if(!isAscending){
                nums[minindex]+=nums[minindex+1];
                nums.erase(nums.begin()+minindex+1);
                count++;
            }
        }
        return count;
    }
};