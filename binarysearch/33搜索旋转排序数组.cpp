#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int last=nums[n-1];
        int left=0;
        int right=n-1;
        int mid;
        while(left<=right){
            mid=(right-left)/2+left;
            if(nums[mid]<=last&&target>last){
                right=mid-1;
                continue;
            }
            if(target<last&&nums[mid]>=last){
                left=mid+1;
                continue;
            }
            if(nums[mid]>target){
                right=mid-1;
                continue;
            }
            if(nums[mid]<target){
                left=mid+1;
                continue;
            }
            if(nums[mid]==target){
                return mid;
            }
        }
        return -1;
    }
};