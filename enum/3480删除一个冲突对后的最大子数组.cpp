#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>>group(n+1);
        for(auto i:conflictingPairs){
            int a=i[0];
            int b=i[1];
            if(a>b)swap(a,b);
            group[a].push_back(b);
        }
        long long ans=0;
        vector<long long>extra(n+2);
        vector<int>b={n+1,n+1};
        for(int i=n;i>0;i--){
            b.insert(b.end(),group[i].begin(),group[i].end());
            sort(b.begin(),b.end());
            b.resize(2);
            ans+=(b[0]-i);
            extra[b[0]]+=(b[1]-b[0]);//?
        }
        long long maximum=INT_MIN;
        for(auto i:extra){
            maximum=max(maximum,i);
        }
        return ans+maximum;
    }
};