#include <bits/stdc++.h>
using namespace std;
class DJset{
    vector<int>parent;
    vector<int>rank;
    public:
        DJset(int n):parent(vector<int>(n)),rank(vector<int>(n)){
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int x){
            if(x!=parent[x]){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
        void merge(int x,int y){
            int fx=find(x);
            int fy=find(y);
            if(rank[fx]<rank[fy]){
                parent[fx]=fy;
            }
            else{
                parent[fy]=fx;
                if(rank[fx]==rank[fy]){
                    rank[fx]++;
                }
            }
        }
};
class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            vector<vector<string>>ans;
            unordered_map<string,int>um;
            int n=accounts.size();
            DJset ds(n);
            for(int i=0;i<n;i++){
                int m=accounts[i].size();
                for(int j=1;j<m;j++){
                    string s=accounts[i][j];
                    if(um.find(s)==um.end()){
                        um[s]=i;
                    }
                    else{
                        ds.merge(i,um[s]);
                    }
                }
            }
            unordered_map<int,vector<string>>umv;
            for(auto&[k,v]:um){
                umv[ds.find(v)].emplace_back(k);
            }
            for(auto&[k,v]:umv){
                sort(v.begin(),v.end());
                vector<string>tmp(1,accounts[k][0]);
                tmp.insert(tmp.end(),v.begin(),v.end());
                ans.emplace_back(tmp);
            }
            return ans;
        }
    };