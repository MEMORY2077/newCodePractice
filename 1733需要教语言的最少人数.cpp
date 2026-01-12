#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
            //你可以选择 一门 语言并教会一些用户，使得所有好友之间都可以相互沟通。请返回你 最少 需要教会多少名用户。
            //没看懂这个一门，原来是我只能选一门教给大家，不能几个学这个另几个学另一个，那就还好说
            unordered_set<int>canttalk;
            for(vector<int>now:friendships){
                //枚举,找到所有不能沟通的组合
                bool can=false;
                unordered_set<int>se(languages[now[1]].begin(),languages[now[1]].end());
                for(int fi:languages[now[0]]){
                    if(se.find(fi)!=se.end()){
                        can=true;
                        break;
                    }
                }
                if(!can)canttalk.emplace(now);
            }
            int teach=0;
            vector<int>languagec(n+1,0);
            for(int now:canttalk){
                for(int lan:languages[now]){
                    languagec[lan]++;
                    teach=max(teach,languagec[lan]);
                }
            }
            teach=canttalk.size()-teach;
            return teach;
        }
    };