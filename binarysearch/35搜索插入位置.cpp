#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid=(r-l)/2+l;
        while(l<=r){
            mid=(r-l)/2+l;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target){
                r=mid-1;
                continue;
            }
            if(nums[mid]<target){
                l=mid+1;
                continue;
            }
        }
        return l;
    }
};