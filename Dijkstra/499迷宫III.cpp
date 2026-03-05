#include <vector>
#include <string>
#include <queue>
using namespace std;
struct State{
    int row;
    int col;
    int dist;
    string path;
    State(int r,int c,int d,const string &p):row(r),col(c),dist(d),path(p){}
};
bool cmp(const State&a,const State&b){
        if(a.dist==b.dist){
            return a.path>b.path;
        }
        return a.dist>b.dist;
}
class Solution {
    const vector<vector<int>>dirs={{0,-1},{-1,0},{0,1},{1,0}};
    const vector<string>dirChar={"l","u","r","d"};
    int m,n;
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        m=maze.size();
        n=maze[0].size();
        priority_queue<State,vector<State>,decltype(cmp)>pq(cmp);
        vector<vector<bool>>seen(m,vector<bool>(n,false));
        pq.emplace(ball[0],ball[1],0,"");
        while(!pq.empty()){
            State cur=pq.top();
            pq.pop();
            if(seen[cur.row][cur.col])continue;
            if(cur.row==hole[0]&&cur.col==hole[1])return cur.path;
            seen[cur.row][cur.col]=true;
            for(const State&nxt:getNeighbors(cur.row,cur.col,maze,hole)){
                pq.emplace(nxt.row,nxt.col,cur.dist+nxt.dist,cur.path+nxt.path);
            }
        }
        return "impossible";
    }
private:
    bool valid(int r,int c,const vector<vector<int>>&maze){
        return r>=0&&c>=0&&r<m&&c<n&&maze[r][c]==0;
    }
    vector<State>getNeighbors(int r,int c,const vector<vector<int>>&maze,const vector<int>&hole){
        vector<State>res;
        for(int i=0;i<4;i++){
            int dy=dirs[i][0];
            int dx=dirs[i][1];
            int nr=r,nc=c,dist=0;
            while(valid(nr+dy,nc+dx,maze)){
                nr+=dy;
                nc+=dx;
                dist++;
                if(nr==hole[0]&&nc==hole[1])break;
            }
            res.emplace_back(nr,nc,dist,dirChar[i]);
        }
        return res;
    }
};