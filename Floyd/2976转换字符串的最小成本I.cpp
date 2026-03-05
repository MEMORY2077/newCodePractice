#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>map(26,vector<long long>(26,INF));
        int n=original.size();
        for(int i=0;i<n;i++){
            int x=original[i]-'a';
            int y=changed[i]-'a';
            long long int c=cost[i];
            map[x][y]=min(c,map[x][y]);
        }
        for(int i=0;i<26;i++){
            map[i][i]=0;
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(map[i][k]==INF)continue;
                    map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
                }
            }
        }
        long long int ans=0;
        int m=source.size();
        for(int i=0;i<m;i++){
            int x=source[i]-'a';
            int y=target[i]-'a';
            //cout<<map[x][y]<<endl;
            if(map[x][y]==INF)return -1;
            ans+=map[x][y];
        }
        return ans;
    }
private:
    const int INF=0x3f3f3f3f;
};