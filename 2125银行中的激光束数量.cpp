#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numberOfBeams(vector<string>& bank) {
            int n=bank.size();
            vector<int>count(n,0);
            int ans=0;
            for(int i=0;i<n;i++){
                for(int row:bank[i]){
                    if(row=='1')count[i]++;
                }
            }
            for(int i=0;i<n;i++){
                if(count[i]==0)continue;
                for(int j=i+1;j<n;j++){
                    if(count[j]==0)continue;
                    ans+=count[i]*count[j];
                    break;
                }
            }
            return ans;
        }
    };