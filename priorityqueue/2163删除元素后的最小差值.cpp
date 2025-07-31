#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m=nums.size();
        int n=m/3;
        vector<long long>suf_max(m-n+1,0);
        long long int sum=0;
        for(int i=m-n;i<m;i++){
            sum+=nums[i];
        }
        suf_max[m-n]=sum;
        priority_queue<int,vector<int>,greater<>>min_pq(nums.end()-n,nums.end());
        for(int i=m-n-1;i>=n;i--){
            int v=nums[i];
            if(v>min_pq.top()){
                sum=sum-min_pq.top()+v;
                min_pq.pop();
                min_pq.push(v);
            }
            suf_max[i]=sum;
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long pre_min=sum;
        long long ans=pre_min-suf_max[n];//i=n-1;
        priority_queue<int,vector<int>,less<>>max_pq(nums.begin(),nums.begin()+n);
        for(int i=n;i<m-n;i++){
            int v=nums[i];
            pre_min+=(v-max_pq.top());
            max_pq.pop();
            max_pq.push(v);
            ans=min(ans,pre_min-suf_max[i+1]);
        }
        return ans;
    }
};