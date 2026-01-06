#include <vector>
using namespace std;
class Solution {
    public:
        long long getDescentPeriods(vector<int>& prices) {
            int n=prices.size();
            vector<long long>s(n+1,0);
            //0 1 3 6 10
            long long int ans=0;
            for(int i=1;i<=n;i++){
                s[i]=s[i-1]+i;
                //cout<<s[i]<<' ';
            }
            long long int sum=1;
            for(int i=1;i<n;i++){
                if(prices[i]==prices[i-1]-1){
                    sum++;
                }
                else{
                    ans+=s[sum];
                    sum=1;
                }
            }
            ans+=s[sum];
            return ans;
        }
    };