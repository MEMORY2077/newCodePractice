#include <string>
#include <algorithm>
#include <vector>
using std::vector,std::string,std::sort;
class Solution {
    public:
        vector<string> removeAnagrams(vector<string>& words) {
            vector<string>myword(words);
            int n=myword.size();
            for(string&now:myword){
                sort(now.begin(),now.end());
            }
            for(int i=1;i<words.size();i++){
                if(myword[i-1]==myword[i]){
                    words.erase(words.begin()+i);
                    myword.erase(myword.begin()+i);
                    i--;
                }
            }
            return words;
        }
    };