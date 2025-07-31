#include <iostream>
#include <vector>
#include <deque>
//单调队列做法
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        int n=nums.size();
        vector<int>ans(n-k+1,0);
        for(int i=0;i<n;i++){
            while(!q.empty()&&nums[q.back()]<=nums[i]){
                q.pop_back();//右侧不符合条件全弹出
            }
            q.push_back(i);//右侧加入
            if(q.front()<i-k+1)q.pop_front();//左侧淘汰(不在窗口内)
            if(i-k+1>=0){
                ans[i-k+1]=nums[q.front()];
            }
        }
        return ans;
    }
};