#include <vector>
using namespace std;
class Solution {
    public:
        bool isOneBitCharacter(vector<int>& bits) {
            int n=bits.size();
            if(n==1)return true;
            if(bits[n-2]==0)return true;
            for(int i=0;i<=n-2;){
                if(i==n-2)return false;
                //if(i==n-3&&bits[i]!=0)return true;
                if(bits[i]==1)i+=2;
                else i+=1;

            }
            return true;
        }
    };