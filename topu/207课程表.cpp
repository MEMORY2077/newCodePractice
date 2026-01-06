#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int>pre(numCourses,0);
            vector<vector<int>>sheet(numCourses);
            for(vector<int>prerequisite:prerequisites){
                pre[prerequisite[0]]++;
                sheet[prerequisite[1]].push_back(prerequisite[0]);
            }
            stack<int>s;
            for(int i=0;i<numCourses;i++){
                if(pre[i]==0)s.push(i);
            }
            int count=0;
            while(!s.empty()){
                int now=s.top();
                s.pop();
                count++;
                for(int link:sheet[now]){
                    if(--pre[link]==0){
                        s.push(link);
                    }
                }
            }
            if(count!=numCourses)return false;
            return true;
        }
    };