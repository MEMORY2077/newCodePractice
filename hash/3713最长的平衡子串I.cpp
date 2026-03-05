#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        vector<int>count(26,0);
        for(int i=0;i<n;i++){
            fill(count.begin(),count.end(),0);
            for(int j=i;j<n;j++){
                bool flag=true;
                int c =s[j]-'a';
                count[c]++;
                for(auto x:count){
                    if(x>0&&x!=count[c]){
                        flag=false;
                        break;
                    }
                }
                if(flag)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};