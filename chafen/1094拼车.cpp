#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool carPooling(vector<vector<int>>& trips, int capacity) {
            int people[1001]={0};
            for (auto now:trips){
                people[now[1]]+=now[0];
                people[now[2]]-=now[0];
            }
            int a=0;
            for(int now:people){
                a+=now;
                if(a>capacity)return false;
            }
            return true;
        }
    };