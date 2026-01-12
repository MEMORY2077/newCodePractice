#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    public:
        int gcd(int x,int y){
            if(x<y)swap(x,y);
            while(y!=0){
                int a=x/y;
                int b=x%y;
                x=y;
                y=b;
                //x=ay+b
            }
            return x;
        }
        int minOperations(vector<int>& nums) {
            int count=0;
            int n=nums.size();
            int g=nums[0];
            for(int num:nums){
                if(num==1)count++;
                g=gcd(num,g);
            }
            if(g>1)return -1;
            if(count!=0)return n-count;
            int min_len=0x3f3f3f3f;
            for(int i=0;i<n;i++){
                int g=nums[i];
                for(int j=i+1;j<n;j++){
                    g=gcd(g,nums[j]);
                    if(g==1){
                        min_len=min(min_len,j-i+1);
                        break;
                    }
                }
            }
            return min_len+n-2;
        }
    };