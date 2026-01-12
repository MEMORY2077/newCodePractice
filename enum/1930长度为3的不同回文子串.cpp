#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
    public:
        int countPalindromicSubsequence(string s) {
            vector<vector<int>>zimu(26,vector<int>(2,-1));
            int n=s.size();
            for(int i=0;i<n;i++){
                if(zimu[s[i]-'a'][0]==-1){
                    zimu[s[i]-'a'][0]=i;
                }
                zimu[s[i]-'a'][1]=i;
            }
            //unordered_set<string>ans;
            int ans=0;
            for(int i=0;i<26;i++){
                int start=zimu[i][0];
                int end=zimu[i][1];
                unordered_set<char>had;
                for(int j=start+1;j<end;j++){
                    if(had.find(s[j])==had.end()){
                        ans++;
                        had.emplace(s[j]);
                    }
                }
            }
            return ans;
        }
    };