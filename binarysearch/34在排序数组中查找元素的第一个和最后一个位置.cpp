#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return {-1,-1};
        int left=0;
        int right=nums.size()-1;
        int mid;
        int first=-1;
        int last=-1;
        while(left<=right){
            mid=(right-left)/2+left; 
            if(nums[mid]<target){
                left=mid+1;
                continue;
            }
            if(nums[mid]>=target){
                if(nums[mid]==target)first=mid;
                right=mid-1;
                continue;
            }
        }
        left=0;
        right=nums.size()-1;
        while(left<=right){
            mid=(right-left)/2+left; 
            if(nums[mid]<=target){
                if(nums[mid]==target)last=mid;
                left=mid+1;
                continue;
            }
            if(nums[mid]>=target){
                right=mid-1;
                continue;
            }
        }
        return {first,last};
    }
};