#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    void moving(int &x,int &y,char w){
        if(w=='U')y++;
        if(w=='D')y--;
        if(w=='L')x--;
        if(w=='R')x++;
    }
    void removing(int &x,int &y,char w){
        if(w=='U')y--;
        if(w=='D')y++;
        if(w=='L')x++;
        if(w=='R')x--;
    }
    int distinctPoints(string s, int k) {
        set<pair<int,int>>res;
        int x=0,y=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            moving(x,y,s[i]);
            int l=i-k+1;
            if(l<0)continue;
            res.emplace(x,y);
            removing(x,y,s[l]);
        }
        return res.size();
    }
};