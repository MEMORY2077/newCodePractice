#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    unordered_set<int>f(vector<int>&a,int mx){
        a.push_back(1);
        a.push_back(mx);
        sort(a.begin(),a.end());
        unordered_set<int>res;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                //cout<<a[j]-a[i]<<endl;
                res.insert(a[j]-a[i]);
            }
        }
        return res;
    }
    const int MOD = 1000000007;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int>h=f(hFences,m);
        unordered_set<int>v=f(vFences,n);
        int ans=0;
        for(int x:h){
            if(v.count(x)){
                ans = max(x,ans);
            }
        }
        if(ans==0)return -1;
        return 1LL*ans*ans % MOD;
    }
};