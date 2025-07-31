#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>>g(n);
        for(auto&e:edges){
            int x=e[0];
            int y=e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int>xr(n),in(n),out(n);
        dfs(0,-1,xr,in,out,nums,g);
        int ans=INT_MAX;
        for(int x=2;x<n;x++){
            for(int y=1;y<x;y++){
                int a,b,c;
                if(is_ancestor(x,y,in,out)){
                    a=xr[y],b=xr[x]^a,c=xr[0]^xr[x];
                }
                else if(is_ancestor(y,x,in,out)){
                    a=xr[x],b=xr[y]^a,c=xr[0]^xr[y];
                }
                else{
                    a=xr[x],b=xr[y],c=xr[0]^a^b;
                }
                ans=min(ans,max({a,b,c})-min({a,b,c}));
                if(ans==0){
                    return 0;
                }
            }
        }
        return ans;
    }
    void dfs(int x,int fa,vector<int>&xr,vector<int>&in,vector<int>&out,vector<int>& nums,vector<vector<int>>&g){
        in[x]=++clock;
        xr[x]=nums[x];
        for(int y:g[x]){
            if(y!=fa){
                dfs(y,x,xr,in,out,nums,g);
                xr[x]^=xr[y];
            }
        }
        out[x]=clock;
        
    }
    bool is_ancestor(int x,int y,vector<int>&in,vector<int>&out){
        return in[x]<in[y]&&in[y]<=out[x];
    }
    int clock=0;
};