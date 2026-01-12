#include <bits/stdc++.h>
using namespace std;
//翻译真是天才。。。能够到达任一为0的点，我以为是every0，结果是any0
class Solution {
    public:
        bool canReach(vector<int>& arr, int start) {
            int n=arr.size();
            vector<bool>visited(n,false);
            queue<int>q;
            q.push(start);
            visited[start]=true;
            while(!q.empty()){
                int now=q.front();
                q.pop();
                int left=now-arr[now];
                int right=now+arr[now];
                if(right<n&&!visited[right]){
                    q.push(right);
                    visited[right]=true;
                    }
                if(left>=0&&!visited[left]){
                    q.push(left);
                    visited[left]=true;
                }
            }
            for(int i=0;i<n;i++){
                if(visited[i]&&arr[i]==0)return true;
            }
            return false;
        }
    };