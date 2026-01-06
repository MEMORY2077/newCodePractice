#include <bits/stdc++.h>
using namespace std;
class Union{
    vector<int>parent;
    public:
        Union(int n):parent(vector<int>(n,-1)){
        }
        int find(int x){
            if(parent[x]<0)return x;
            parent[x]=find(parent[x]);
            return parent[x];
        }
        void un(int x,int y){
            int fx=find(x);
            int fy=find(y);
            if(fx==fy)return;
            if(fx>fy){//改造一下，方便我做这道题
                parent[fx]=fy;
                parent[fy]--;                
                return;
            }
            if(fx<=fy){
                parent[fy]=fx;
                parent[fx]--;
                return;
            }
            parent[fx]=fy;
            parent[fy]--;
            return;
        }
};
class Solution {
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            int n=s1.size();
            Union onion(27);
            for(int i=0;i<n;i++){
                onion.un(s1[i]-'a',s2[i]-'a');
            }
            n=baseStr.size();
            for(int i=0;i<n;i++){
                baseStr[i]=onion.find(baseStr[i]-'a')+'a';
            }
            return baseStr;
        }
    };