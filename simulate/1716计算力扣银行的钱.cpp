#include <bits/stdc++.h>
using namespace std;
//等差数列
class Solution {
    public:
        int totalMoney(int n) {
            int last=n%7;
            int count=n/7;
            int ans=count*28+(count*(count-1)/2)*7+(count+1)*last+last*(last-1)/2;
            return ans;
            //1 2 3 4 5 6 7 28
            //2 3 4 5 6 7 8 35
        }
    };