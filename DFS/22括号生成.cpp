#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string now;
        dfs(n,now,0);
        return ans;
    }
    void dfs(int n,string now,int next){
        if(now.size()==2*n){
            ans.push_back(now);
            return ;
        }
        if(left+1<=n){
            now.push_back('(');
            left++;
            dfs(n,now,next+1);
            left--;
            now.pop_back();
        }
        if(right+1<=n&&right+1<=left){
            now.push_back(')');
            right++;
            dfs(n,now,next+1);
            right--;
            now.pop_back();
        }
        return;
    }
    int left=0;
    int right=0;
    vector<string>ans;
};