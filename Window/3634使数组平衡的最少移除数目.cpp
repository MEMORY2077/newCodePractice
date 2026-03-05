#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if(nums.size()==1)return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //cout<<n<<endl;
        int ans= 0;
        int r=0;
        for(int l=0;l<n;l++){
            //r=l;
            long long int kn=1LL*k*nums[l];
            while(r+1<n&&nums[r+1]<=kn)r++;
            ans=max(r-l+1,ans);
        }
        return n-ans;
    }
};