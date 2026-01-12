#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> getNoZeroIntegers(int n) {
            int k=n/2;
            for(int i=1;i<=k;i++){
                if(test(i)&&test(n-i)){
                    return {i,n-i};
                }
            }
            return {};
        }
        bool test(int x){
            if(x==0)return false;
            while(x!=0){
                if(x%10==0)return false;
                x/=10;
            }
            return true;
        }
    };
int main(void){
    Solution a;
    a.getNoZeroIntegers(11);
    return 0;
}