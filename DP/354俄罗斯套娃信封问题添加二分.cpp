#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            int n=envelopes.size();
            sort(envelopes.begin(),envelopes.end(),us2sort);
            vector<int>f={envelopes[0][1]};
            for(int i=1;i<n;i++){
                int now=envelopes[i][1];
                if(now>f.back()){
                    f.push_back(now);
                }
                else{
                    auto it=lower_bound(f.begin(),f.end(),now);
                    *it=now;
                }
            }
            return f.size();            
        }
        static bool us2sort(vector<int>&a,vector<int>&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        }
    };