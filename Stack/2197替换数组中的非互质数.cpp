#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
    public:
        vector<int> replaceNonCoprimes(vector<int>& nums) {
            vector<int>s;
            for(int x:nums){
                while(!s.empty()&&gcd(x,s.back())!=1){
                    x=lcm(x,s.back());
                    s.pop_back();
                }
                s.push_back(x);
            }
            return s;
        }
        int gcd(int x,int y){
            if(x<y){
                swap(x,y);
            }
            while(y!=0){
                int c=y;
                y=x%y;
                x=c;
            }
            return x;
        }
        int lcm(int x,int y){
            int g=gcd(x,y);
            return (long long)x*(long long)y/g;
        }
    };