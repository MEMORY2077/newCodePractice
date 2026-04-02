#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        string now="";
        if(dfs(now,n,k))return ans;
        return "";
    }
    bool dfs(string &now,int n,int k){
        int l=now.length();
        if(l==n){
            cnt++;
            if(cnt>=k){
                ans=now;
                return true;
            }
            return false;
        }
        for(int i=0;i<3;i++){
            if((l-1>=0&&now[l-1]!=dic[i])||l==0){
                now.push_back(dic[i]);
                if(dfs(now,n,k))return true;
                now.pop_back();
            }
        }
        return false;
    }
private:
    string dic="abc";
    string ans;
    int cnt=0;
};