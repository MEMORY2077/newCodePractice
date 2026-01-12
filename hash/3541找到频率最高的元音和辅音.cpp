#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int maxFreqSum(string s) {
            unordered_map<char,int>letter;
            int maxv=0;
            int maxnv=0;
            for(char now:s){
                letter[now]++;
                if(now=='a'||now=='e'||now=='i'||now=='o'||now=='u'){
                    maxv=max(maxv,letter[now]);
                }
                else maxnv=max(maxnv,letter[now]);
            }
            return maxv+maxnv;
        }
    };