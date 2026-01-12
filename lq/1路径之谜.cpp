#include <iostream>
#include <vector>
using namespace std;
int N=0;
int DIR[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool dfs(vector<int>visit,vector<int>&ans,int now,vector<int>row,vector<int>col){
    int x=now/N;
    int y=now%N;
    //ans.push_back(now);
    row[x]-=1;
    col[y]-=1;
    if(now==N*N-1){
        for(int i=0;i<N;i++){
            //cout<<row[i]<<' '<<col[y]<<endl;
            if(row[i]!=0||col[i]!=0){
                return false;
            }
        }
        return true;
    }
    for(int i=0;i<4;i++){
        int nx=x+DIR[i][0];
        int ny=y+DIR[i][1];
        if(nx>=0&&nx<N&&ny>=0&&ny<N){
            int next=nx*N+ny;
            if(visit[next]!=1&&row[nx]-1>=0&&col[ny]-1>=0){
                visit[next]=1;
                ans.push_back(next);
                if(dfs(visit,ans,next,row,col))return true;
                ans.pop_back();
                visit[next]=0;
            }
        }
    }
    return false;
}
int main(void){
    cin>>N;
    vector<int>row(N,0);
    vector<int>col(N,0);
    for(int i=0;i<N;i++){
        cin>>col[i];
    }
    for(int i=0;i<N;i++){
        cin>>row[i];
    }
    vector<int>visit(N*N,0);
    vector<int>ans;
    ans.push_back(0);
    visit[0]=1;
    dfs(visit,ans,0,row,col);
    int n=ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    //cout<<endl;
    return 0;
}