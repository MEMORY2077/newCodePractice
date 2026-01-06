#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
            unordered_set<string>origin(wordlist.begin(),wordlist.end());
            unordered_map<string,string>below;
            unordered_map<string,string>change;
            int n=wordlist.size();
            for(int i=n-1;i>=0;i--){
                string index=tolower_string(wordlist[i]);
                below[index]=wordlist[i];
                index=bemohu(index);
                change[index]=wordlist[i];
            }
            int m=queries.size();
            vector<string>ans(m,"");
            for(int i=0;i<m;i++){
                auto now=origin.find(queries[i]);
                if(now!=origin.end()){
                    ans[i]=queries[i];
                }
                else{
                    string s=tolower_string(queries[i]);
                    auto no=below.find(s);
                    if(no!=below.end()){
                        ans[i]=no->second;
                    }
                    else{
                        s=bemohu(s);
                        auto nowc=change.find(s);
                        if(nowc!=change.end()){
                            ans[i]=nowc->second;
                        }
                    }
                }
            }
            return ans;
        }
        string tolower_string(string now){
            string ans=now;
            for(char &achar:ans){
                if(achar>='A'&&achar<='Z')achar+=('a'-'A');
            }
            return ans;
        }
        string bemohu(string now){
            string ans=now;
            for(char &achar:ans){
                if(achar=='A'||achar=='E'||achar=='I'||achar=='O'||achar=='U'||achar=='a'||achar=='e'||achar=='i'||achar=='o'||achar=='u'){
                    achar='*';
                }
            }
            return ans;
        }
    };