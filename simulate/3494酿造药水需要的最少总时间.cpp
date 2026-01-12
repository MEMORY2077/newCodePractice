#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long minTime(vector<int>& skill, vector<int>& mana) {
            int n=skill.size();
            vector<int>last_finish(skill.size(),n);
            for(int now:mana){
                int sum=0;
                for(int i=0;i<n;i++){
                    sum=max(sum,last_finish[i])+now*skill[i];
                }
                last_finish[n-1]=sum;
                for(int i=n-2;i>=0;i--){
                    last_finish[i]=last_finish[i+1]-skill[i+1]*now;
                }
            }
            return last_finish[n-1];
        }
    };