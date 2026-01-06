#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
        //static bool us2sort()
        unordered_map<string,int>business={{"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}};
        string a="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
        vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
            int n=code.size();
            unordered_set<char>dict(a.begin(),a.end());
            vector<string>group[4];
            vector<string>ans;
            for(int i=0;i<n;i++){
                if(!isActive[i])continue;
                if(code[i].empty())continue;
                bool flag=false;
                for(char c:code[i]){
                    if(dict.find(c)==dict.end()){
                        flag=true;
                        break;
                    }
                }
                if(flag)continue;
                auto it=business.find(businessLine[i]);
                if(it==business.end())continue;
                group[it->second].push_back(code[i]);
            }
            for(auto&g:group){
                sort(g.begin(),g.end());
                ans.insert(ans.end(),g.begin(),g.end());
            }
            return ans;
        }
    };