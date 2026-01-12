#include <vector>
#include <queue>
using namespace std;
class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            queue<int>key;
            key.push(0);
            int n=rooms.size();
            vector<int>visited(n,0);
            while(!key.empty()){
                int now=key.front();
                key.pop();
                visited[now]=1;
                for(int nkey:rooms[now]){
                    if(visited[nkey]==0){
                        key.push(nkey);
                    }
                }
            }
            for(int test:visited){
                if(test==0)return false;
            }
            return true;
        }
    };