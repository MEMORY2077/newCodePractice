#include <vector>
using namespace std;
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int k=target/sum;
        target-=sum*k;
        if(target==0)return n*k;
        int l=0;
        int ans=0x3f3f3f3f;;
        for(int i=0;i<n*2;i++){
            target-=nums[i%n];
            while(target<0){
                target+=nums[l%n];
                l++;
            }
            if(target==0)ans=min(ans,i-l+1);
        }
        if(ans==0x3f3f3f3f)return -1;
        return n*k+ans;
    }
};