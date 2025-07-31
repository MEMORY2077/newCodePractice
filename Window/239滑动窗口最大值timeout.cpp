#include <iostream>
#include <vector>
using namespace std;
//左指针正好是最大值时候不知道怎么搞🤔
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        vector<int>maximum(n-k+1,INT_MIN);
        for(r=0;r<k;r++){
            maximum[0]=max(maximum[0],nums[r]);
        }
        while(r<n){
            if(maximum[l]==nums[l]){
                for(int i=0;i<k;i++){
                    maximum[l+1]=max(maximum[l+1],nums[l+1+i]);
                }
            }
            else{
                maximum[l+1]=max(maximum[l],nums[r]);
            }
            l++;
            r++;
        }
        return maximum;
    }
};