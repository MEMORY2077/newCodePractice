#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string ans;
        int count=0;
        stack<int>c;//数字栈
        stack<string>l;//字符串栈
        string astr;//当前字符串
        for(char now:s){
            if(now>='0'&&now<='9'){//数，压入栈
                count*=10;
                count+=(now-'0');
                continue;
            }
            if(count!=0){
                c.push(count);
                count=0;
            }
            if(now=='['){//左括号，将当前字符串压入栈，astr清空，模拟递归
                l.push(astr);
                astr="";
                continue;
            }
            if(now==']'){//右括号，模拟递归
                string a;//当前层次的字符串
                int count=c.top();//重复次数
                c.pop();//弹出次数
                for(int i=0;i<count;i++){
                    a+=astr;//重复
                }
                astr=l.top();//取出上一层的字符串，模拟递归返回
                l.pop();//弹栈
                astr+=a;//上一层字符串加上本层字符串
                continue;
            }
            astr.push_back(now);//啥也不是，直接接在字符串后面
        }
        return astr;
    }
};