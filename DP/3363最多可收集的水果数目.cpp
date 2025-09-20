#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int ans=0;
        //第一个小朋友
        for(int i=0;i<n;i++){
            ans+=fruits[i][i];
        }
        ans+=dp(fruits);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                fruits[j][i]=fruits[i][j];
            }
        }
        ans+=dp(fruits);
        return ans;
    }
    int dp(vector<vector<int>>& fruits){
        int n=fruits.size();
        vector<vector<int>>f(n+1,vector<int>(n+1,0));
        f[0][n-1]=fruits[0][n-1];
        for(int i=1;i<n-1;i++){
            for(int j=max(n-1-i,i+1);j<n;j++){
                f[i][j]=max({f[i-1][j-1],f[i-1][j],f[i-1][j+1]})+fruits[i][j];
            }
        }
        cout<<f[n-2][n-1]<<' ';
        return f[n-2][n-1];
    }
};