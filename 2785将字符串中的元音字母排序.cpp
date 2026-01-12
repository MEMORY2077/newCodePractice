#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        string sortVowels(string s) {
            string Sortvi;
            unordered_set<char>vi={'a','e','i','o','u','A','E','I','O','U'};
            for(char now:s){
                if(vi.find(now)!=vi.end()){
                    Sortvi+=now;
                }
            }
            sort(Sortvi.begin(),Sortvi.end());
            int j=0;
            for(char &now:s){
                if(vi.find(now)!=vi.end()){
                    now=Sortvi[j];
                    j++;
                }
            }
            return s;
        }
    };