#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int last=nums[n-1];
        int left=0;
        int right=n-1;
        int mid;
        while(left<=right){
            mid=(right-left)/2+left;
            int x=nums[mid];
            if(x>last){
                left=mid+1;
                continue;
            }
            if(x<last){
                right=mid-1;
                continue;
            }
        }
        return mid;
    }
};
