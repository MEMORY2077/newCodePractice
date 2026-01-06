#include <bits/stdc++.h>
using namespace std;
class Union{
    vector<int>parent;
    public:
    Union(int n):parent(vector<int>(n,-1)){}
    int find(int x){
        if(parent[x]<0)return x;
            parent[x]=find(parent[x]);
        return parent[x];
    }
    bool check(int x,int y){
        int fx=find(x);
        int fy=find(y);
        return fx==fy;
    }
    void un(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)return;
        if(parent[fx]>parent[fy]){//x比较短
            parent[fx]=fy;
        }
        else if(parent[fx]<parent[fy]){
            parent[fy]=fx;
        }
        else{
            parent[fy]-=parent[fx];
            parent[fx]=fy;
        }
    }
};
class Solution {
    public:
        bool equationsPossible(vector<string>& equations) {
            Union uu(27);
            for(string now:equations){
                if(now[1]=='='){
                    uu.un(now[0]-'a',now[3]-'a');
                }
            }
            for(string now:equations){
                if(now[1]=='!'){
                    if(uu.check(now[0]-'a',now[3]-'a'))return false;
                }
            }
            return true;
        }
    };