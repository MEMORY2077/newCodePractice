#include <vector>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        //10 11 101 111 1011
        int n=nums.size(); 
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int now=nums[i];
            for(int j=0;j<now;j++){
                if((j|(j+1))==now){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
};