#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countValidSelections(vector<int>& nums) {
            int ans=0;
            int n=nums.size();
            stack<int>s;
            for(int i=0;i<n;i++){
                if(nums[i]==0)s.push(i);
            }
            int dir[2]={-1,1};
            while(!s.empty()){
                int d=0;
                vector<int>temp=nums;
                int curr=s.top();                    
                //左
                while(curr>=0&&curr<n){
                    if(temp[curr]==0){
                        curr+=dir[d];
                    }
                    else{
                        temp[curr]--;
                        d=(d+1)%2;
                        curr+=dir[d];
                    }
                }
                for(int i=0;i<n;i++){
                    if(temp[i]!=0){
                        ans--;
                        break;
                    }
                }
                ans++;
                d=1;
                temp=nums;
                curr=s.top();                    
                //右走
                while(curr>=0&&curr<n){
                    if(temp[curr]==0){
                        curr+=dir[d];
                    }
                    else{
                        temp[curr]--;
                        d=(d+1)%2;
                        curr+=dir[d];
                    }
                }
                for(int i=0;i<n;i++){
                    if(temp[i]!=0){
                        ans--;
                        break;
                    }
                }
                ans++;
            s.pop();
            }
            return ans;
        }
    };