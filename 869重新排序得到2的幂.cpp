#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
unordered_set<string>pow2strset;
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        const int MAX_N=1000000000;
        for(int i=1;i<MAX_N;i<<=1){
            string s=int2sortstr(i);
            pow2strset.insert(s);
        }
        string s=int2sortstr(n);
        if(pow2strset.find(s)!=pow2strset.end()){
            return true;
        }
        return false;
    }
    static string int2sortstr(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
};