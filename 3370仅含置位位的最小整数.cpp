#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int smallestNumber(int n) {
            int last=log2(n)+1;
            int next=pow(2,last)-1;
            return next;
        }
    };