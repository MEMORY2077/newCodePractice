#include <vector>
using namespace std;
//这题很有意思，概率dp，同时算是教了我记忆化搜索
class Solution {
public:
    double soupServings(int n) {
        if(n>=5000)return 1;
        n=(n+24)/25;
        MEMORY=vector<vector<double>>(n+1,vector<double>(n+1,0));
        double ans=dfs(n,n);
        return ans;
    }
private:
    vector<vector<double>>MEMORY;
    double dfs(int a,int b){
        if(a<=0&&b<=0){
            return 0.5;
        }
        if(a<=0&&b>0){
            return 1;
        }
        if(a>0&&b<=0){
            return 0;
        }
        if(MEMORY[a][b]<=0){
            MEMORY[a][b]=(dfs(a-4,b)+dfs(a-3,b-1)+dfs(a-2,b-2)+dfs(a-1,b-3))/4;
        }
        return MEMORY[a][b];
    }
};