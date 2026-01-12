#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        int smallestRepunitDivByK(int k) {
            unsigned long long int n=1;
            if(k%2==0||k%5==0)return -1;
            unordered_set<int>h;
            int x=1%k;
            for(int i=1;;i++){
                if(x==0)return i;
                //if(h.count(now))return -1;
                //h.emplace(now);
                x=(x*10+1)%k;
            }
            return -1;
        }
    };