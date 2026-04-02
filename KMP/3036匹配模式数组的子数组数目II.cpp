#include <vector>
using namespace std;
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m =pattern.size();
        vector<int>pi(m);
        int cnt=0;
        for(int i=1;i<m;i++){
            int v=pattern[i];
            while(cnt&&pattern[cnt]!=v)cnt=pi[cnt-1];
            if(pattern[cnt]==v)cnt++;
            pi[i]=cnt;
            //0,0,1,2
        }
        int ans=0;
        cnt=0;
        for(int i=1;i<nums.size();i++){
            int x=nums[i-1],y=nums[i];
            int v=(y>x)-(y<x);
            while(cnt&&pattern[cnt]!=v){
                cnt=pi[cnt-1];
            }
            if(pattern[cnt]==v){
                cnt++;
            }
            if(cnt==m){
                ans++;
                cnt=pi[cnt-1];
            }
        }
        return ans;
    }
};