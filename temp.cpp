#include <string>
#include <stack>
using namespace std;
int Calculate(string P,int n){
    int ans=0;
    if (P=="0")return 0;
    stack<int>s;
    int now=0;
    for(int i=0;i<n;i++){
        if(P[i]>='0'&&P[i]<='9'){
            now*=10;
            now+=(P[i]-'0');
            continue;
        }
        if(P[i]==' '){
            s.push(now);
            now = 0;
            continue;
        }
        else{
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            int num3 = 0;
            switch (P[i]){
                case '+':{
                    num3 = num1 + num2;
                    break;
                }
                case '-':{
                    num3 = num1 - num2;
                    break;
                }
                case '*':{
                    num3 = num1 * num2;
                    break;
                }
                case '/':{
                    if(num2==0)exit(-1);
                    num3 = num1 / num2;
                    break;
                }
            }
            s.push(num3);
            i++;
        }
    }
    if(now!=0)return now;
    return s.top();
}
string InfixToPostfix(string P){
    stack<string>N;
    stack<char>S;
    int now=0;
    for(char now:P){
        
    }
}
int readnum(string s, int n, int &i){
    int temp = 0;
    while(i<n && s[i] >= '0' && s[i] <= '9'){
        temp = temp * 10 + s[i] - '0';
        i++;
    }
    i--;
    return temp;
}
bool operation(stack<int> &num,stack<char>&OP){
    char t=OP.top();
    OP.pop();
    int b=num.top();
    num.pop();
    int a=num.top();
    num.pop();
    if(t=='+'){
        num.push(a+b);
    }
    if(t=='-'){
        num.push(a-b);
    }
    if(t=='*'){
        num.push(a*b);
    }
    if(t=='/'){
        if(b==0)return false;
        num.push(a/b);
    }
    return true;
}
int calculate(string s){
    stack<int> num;
    stack<char> OP;
    int n=s.size();
    int p[100]={0};
    p['+']=p['-']=1;
    p['*']=p['/']=2;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9')num.push(readnum(s,n,i));
        else if(s[i]=='(')OP.push(s[i]);
        else if(s[i]==')'){
            while(OP.top()!='('){
                operation(num,OP);
            }
            OP.pop();
        }
        else{
            while(!OP.empty()&&OP.top()!='('&&p[s[i]]<=p[OP.top()]){
                operation(num,OP);
            }
            OP.push(s[i]);
        }
    }
    while(!OP.empty())operation(num,OP);
    return num.top();
}