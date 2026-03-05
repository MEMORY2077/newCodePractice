#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int pu=0;
        stack<int>s;
        int i=a.length()-1,j=b.length()-1;
        for(i,j;i>=0&&j>=0;i--,j--){
            int a1=a[i]-'0';
            int b1=b[j]-'0';
            int c1=(a1+b1+pu)%2;
            pu=(a1+b1+pu)/2;
            s.push(c1);
        }
        while(i>=0){
            s.push((a[i]-'0'+pu)%2);
            pu=(a[i]-'0'+pu)/2;
            i--;
        }
        while(j>=0){
            s.push((b[j]-'0'+pu)%2);
            pu=(b[j]-'0'+pu)/2;
            j--;
        }
        if(pu!=0)res="1";
        while(!s.empty()){
            //cout<<s.top();
            res.push_back(s.top()+'0');
            s.pop();
        }
        return res;
    }
};