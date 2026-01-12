#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        long long maxRunTime(int n, vector<int>& batteries) {
            long long int sum=0;
            for(int battery:batteries){
                sum+=battery;
            }
            long long int r=sum/n+1;
            long long int l=0;
            while(l+1<r){
                long long mid=l+(r-l)/2;
                long long sum=0;
                for(long long b:batteries){
                    sum+=min(b,mid);
                }
                if(n*mid<=sum)l=mid;
                else r=mid;
            }
            return l;
        }
    };