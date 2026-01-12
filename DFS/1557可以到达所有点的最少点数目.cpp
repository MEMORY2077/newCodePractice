#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
            unordered_set<int>InTheEnd;
            for(auto edge:edges){
                InTheEnd.emplace(edge[1]);
            }
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(InTheEnd.find(i)==InTheEnd.end()){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };