#include <vector>
#include <unordered_map>
using std::vector,std::unordered_map;
class Solution {
    public:
        int findSmallestInteger(vector<int>& nums, int value) {
                unordered_map<int,int>amap;
                for(int num:nums){
                    amap[(num%value+value)%value]++;
                }
                int mes=0;
                while(amap.find(mes%value)!=amap.end()){
                    mes++;
                }
                return mes;
        }
    };