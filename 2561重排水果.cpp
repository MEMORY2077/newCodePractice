#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool us2sort(int &a,int &b){
        return a>b;
    }
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>cnt;
        int n=basket1.size();
        for(int i=0;i<n;i++){
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
        }
        int mn=INT_MAX;
        vector<int>a;
        vector<int>b;
        for(auto [x,c]:cnt){
            if(c%2!=0)return -1;
            mn=min(mn,x);
            if(c>0){
                for(int i=0;i<c/2;i++){
                    a.push_back(x);
                }
            }
            else{
                for(int i=0;i>c/2;i--){
                    b.push_back(x);
                }
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),us2sort);
        n=a.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=min({a[i],b[i],2*mn});
        }
        return ans;
    }
};