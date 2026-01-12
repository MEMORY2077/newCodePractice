#include <bits/stdc++.h>
using namespace std;
class Union{
    vector<int>parents;
    public:
        Union(int n):parents(vector<int>(n,-1)){}
        int find(int x){
            if(parents[x]<0)return x;
            parents[x]=find(parents[x]);
            return parents[x];
        }
        void un(int x,int y){
            int fx=find(x);
            int fy=find(y);
            if(fx==fy)return;
            if(parents[fx]<parents[fy]){
                parents[fy]=fx;
                return;
            }
            if(parents[fx]>parents[fy]){
                parents[fx]=fy;
                return;
            }
            parents[fy]=fx;
            parents[fx]--;
            return;
        }
        bool check(int x,int y){
            if(find(x)==find(y))return true;
            return false;
        }
        int count(){
            int c=0;
            int n=parents.size();
            for(int i=0;i<n;i++){
                if(parents[i]<0)c++;
            }
            return c;
        }
};
class Solution {
    public:
        bool check(const string &a1,const string &a2){
            int n=a1.size();
            int count=0;
            for(int i=0;i<n;i++){
                if(a1[i]!=a2[i])count++;
                if(count>2)return false;
            }
            return true;
        }
        int numSimilarGroups(vector<string>& strs) {
            int n=strs.size();
            Union onion(n);
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(onion.check(i,j))continue;//两人已经在一起了
                    if(check(strs[i],strs[j])){
                        onion.un(i,j);
                    }
                }
            }
            int count=onion.count();
            return count;
        }
    };