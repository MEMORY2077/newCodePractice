#include <vector>
#include <string>
#
using namespace std;
class Solution {
    public:
        bool doesAliceWin(string s) {
            
            int ve=0;
            for(char now:s){
                if(now=='a'||now=='e'||now=='i'||now=='o'||now=='u'){
                    ve++;
                }
            }
            if(ve==0)return false;
            return true;

        }
    };