#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int>nums1;
    vector<int>nums2;
    vector<vector<int>>dp;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        dp=vector<vector<int>>(m,vector<int>(n,INT_MAX));
        this->nums1=nums1;
        this->nums2=nums2;
        return dfs(m-1,n-1);
    }
    int dfs(int i,int j){
        if(i<0||j<0)return INT_MIN;
        int &res=dp[i][j];
        if(res!=INT_MAX){
            return res;
        }
        res=max(dfs(i-1,j-1),0)+nums1[i]*nums2[j];
        res=max(res,dfs(i-1,j));
        res=max(res,dfs(i,j-1));
        return res;
    }
};