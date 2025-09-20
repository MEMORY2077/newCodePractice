#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>basket;
        int left=0;
        int ans=0;
        int result=0;
        for(int right=left;right<fruits.size();right++){
            basket[fruits[right]]++;
            ans++;
            while(basket.size()>2){
                ans--;
                if(--basket[fruits[left]]==0)basket.erase(fruits[left]);
                left++;
            }
            result=max(result,ans);
        }
        return result;
    }
};