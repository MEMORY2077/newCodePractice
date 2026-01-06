#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int finalValueAfterOperations(vector<string>& operations) {
            int x=0;
            unordered_map<string,int>oper;
            oper["X++"]=1;
            oper["X--"]=-1;
            oper["++X"]=1;
            oper["--X"]=-1;
            for(string now:operations){
                x+=oper[now];
            }
            return x;
        }
    };