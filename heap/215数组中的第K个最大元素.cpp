#include <vector>
using namespace std;
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            buildheap(nums);
            int n=nums.size()-1;
            for(int i=0;i<k-1;i++){
                del(nums,n,0);
            }
            return nums[0];
        }
        void buildheap(vector<int>&nums){
            int n=nums.size()-1;
            for(int i=n/2;i>=0;i--){
                shiftdown(nums,n,i);
            }
        }
        void shiftup(vector<int>&nums,int n,int k){
            while(k>0&&nums[k]>nums[k/2]){
                swap(nums[k],nums[k/2]);
                k/=2;
            }
        }
        void shiftdown(vector<int>&nums,int n,int k){
            while(k<=n/2){
                int maxChd=2*k;
                if(maxChd+1<=n&&nums[maxChd]<nums[maxChd+1]){
                    maxChd++;
                }
                if(nums[k]>=nums[maxChd])return;
                swap(nums[k],nums[maxChd]);
                k=maxChd;
            }
        }
        void del(vector<int>&nums,int &n,int w){
            swap(nums[n],nums[w]);
            n--;
            shiftdown(nums,n,0);
        }
    };