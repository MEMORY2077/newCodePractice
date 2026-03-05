#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        stack<int>s;
        bool flag=false;
        if(num==0)return "0";
        if(num<0){
            num = -num;
            flag = true;
        }
        while(num!=0){
            s.push(num%7);
            num/=7;
        }
        string ans;
        if(flag)ans.push_back('-');
        while(!s.empty()){
            ans.push_back(s.top()+'0');
            s.pop();
        }

        return ans;
    }
};