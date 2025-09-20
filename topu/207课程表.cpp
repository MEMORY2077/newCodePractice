#include <iostream>
#include <vector>
#include <queue>
struct Edge{
    int go;
    Edge*next;
    Edge(int go=-1,Edge*next=nullptr){
        this->go=go;
        this->next=next;
    }
};
struct Vertex{
    Edge*adj=nullptr;
    Vertex(Edge*adj=nullptr){
        this->adj=adj;
    }
};
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Vertex>head(numCourses);
        vector<int>in(numCourses,0);
        for(auto now:prerequisites){
            head[now[0]].adj=new Edge(now[1],head[now[0]].adj);
            in[now[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!in[i])q.push(i);
        }
        for(int i=0;i<numCourses;i++){
            if(q.empty())return false;
            int now=q.front();
            q.pop();
            for(Edge*p=head[now].adj;p!=nullptr;p=p->next){
                if(--in[p->go]==0){
                    q.push(p->go);
                }
            }
        }
        return true;
    }
};