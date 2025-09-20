#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>astack;
        for(char now:s){
            if(now=='{'||now=='['||now=='('){
                astack.push(now);
            }
            else{
                if(astack.empty())return false;
                if(now=='}'){
                    if(astack.top()!='{')return false;
                    astack.pop();
                }
                else if(now==']'){
                    if(astack.top()!='[')return false;
                    astack.pop();
                }
                else if(now==')'){
                    if(astack.top()!='(')return false;
                    astack.pop();
                }
            }
        }
        if(!astack.empty())return false;
        return true;
    }
};