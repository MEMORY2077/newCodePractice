#include <iostream>
#include <deque>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>have;
        deque<int>wind;
        int maximum=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(have.find(nums[i])==have.end()){
                //不在当前窗口
                sum+=nums[i];//加和
                wind.push_back(nums[i]);
                have.emplace(nums[i]);
            }
            else{
                //当前窗口有,一直弹出直到给他弹出去
                while(wind.front()!=nums[i]){
                    sum-=wind.front();
                    have.erase(nums[i]);
                    wind.pop_front();
                }
                wind.pop_front();
                wind.push_back(nums[i]);
            }
            maximum=max(maximum,sum);
        }
        return maximum;
    }
};