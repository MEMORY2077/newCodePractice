#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        vector<int> replaceNonCoprimes(vector<int>& nums) {
            /*unordered_set<int>check;
            for(int i=0;i<nums.size();i++){
                if(check.find(nums[i])==check.end()){
                    check.insert(nums[i]);
                }
                else{
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }*/
            int flag=true;
            while(flag){
                flag=false;
                for(int i=0;i<nums.size()-1;i++){
                    int g=gcd(nums[i],nums[i+1]);
                    if(g!=1){
                        flag=true;
                        int l=(long long)nums[i]*(long long )nums[i+1]/g;
                        nums[i]=l;
                        nums.erase(nums.begin()+i+1);
                        i--;
                    }
                }
            }
            return nums;
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
    };