#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>path;
        dfs(s,0,path);
        return ans;
    }
    void dfs(string &s,int next,vector<string>&path){
        if(next>=s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=next;i<s.size();i++){
            if(check(s,next,i)){
                string str=s.substr(next,i-next+1);
                path.push_back(str);
                dfs(s,i+1,path);
                path.pop_back();
            }
        }
    }
    bool check(string now,int start,int end){
        while(start<end){
            if(now[start++]!=now[end--])return false;
        }
        return true;
    }
    vector<vector<string>>ans;
};