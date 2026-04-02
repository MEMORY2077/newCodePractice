#include <vector>
#include <string>
#include <bit>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool queryString(string s, int n) {//因为判断1——n的所有数，短的数一定会被长的数覆盖，所以只需要判断长的就行
        if(n==1)return s.find('1')!=string::npos;
        int m=s.length();
        int k=31-__builtin_clz(n);//n位宽-1，滑窗大小
        if(m<max(n-(1<<k)+k+1,(1<<(k-1))+k-1))return false;
        auto check = [&](int k,int lower,int upper)->bool{
            if(lower>upper)return true;
            unordered_set<int>seen;
            int mask = (1<<(k-1))-1;//去掉最高位，出队
            int x=stoi(s.substr(0,k-1),nullptr,2);
            for(int i=k-1;i<m;i++){
                x=((x&mask)<<1)|s[i]-'0';//左移再或就是入
                if(lower<=x&&x<=upper)seen.insert(x);
            }
            return seen.size()==upper-lower+1;
        };
        return check(k,n/2+1,(1<<k)-1)&&check(k+1,1<<k,n);
    }
};