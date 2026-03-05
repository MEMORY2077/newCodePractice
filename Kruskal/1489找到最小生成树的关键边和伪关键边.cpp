#include <vector>
#include <algorithm>

using namespace std;
class UnionFind{
public:
    vector<int>parents;
    int setCount;
    UnionFind(int n){
        parents=vector<int>(n,-1);
        setCount=n;
    }
    int find(int x){
        if(parents[x]<0)return x;
        parents[x]=find(parents[x]);
        return parents[x];
    }
    int Union(int x,int y){
        int px=find(x);
        int py=find(y);
        setCount--;
        if(px==py){
            setCount++;
            return false;
        }
        if(parents[px]<parents[py]){
            parents[py]=px;
            return true;
        }
        else if(parents[px]>parents[py]){
            parents[px]=py;
            return true;
        }
        else {
            parents[py]=px;
            parents[px]--;
            return true;
        }
        return true;
    }
    bool check(int x,int y){
        if(find(x)==find(y))return true;
        return false;
    }
};
class Solution {
public:
    static bool us2sort(const vector<int>&u,const vector<int>&v){
        return u[2]<v[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),us2sort);
        UnionFind uf_ori(n);
        int value=0;

        for(int i=0;i<m;i++){
            if(uf_ori.Union(edges[i][0],edges[i][1])){
                value+=edges[i][2];
            }
        }
        vector<vector<int>>ans(2);
        for(int i=0;i<m;i++){
            //判断每条边是否为关键边
            UnionFind uf(n);
            int v=0;
            for(int j=0;j<m;j++){
                if(i!=j&&uf.Union(edges[j][0],edges[j][1])){
                    v+=edges[j][2];
                }
            }
            if(uf.setCount!=1||(v>value)){
                ans[0].push_back(edges[i][3]);
                continue;
            }
            //判断伪关键边
            uf=UnionFind(n);
            uf.Union(edges[i][0],edges[i][1]);
            v=edges[i][2];
            for(int j=0;j<m;j++){
                if(i!=j&&uf.Union(edges[j][0],edges[j][1])){
                    v+=edges[j][2];
                }
            }
            if(v==value){
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};