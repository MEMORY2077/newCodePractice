#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//注意这题的2数组长度特别大，直接查询耗时极长，用哈希表
class FindSumPairs {
public:
    FindSumPairs(vector<int>& Nums1, vector<int>& Nums2):sums1(Nums1),sums2(Nums2){
        for(int i=0;i<sums2.size();i++){
            cnt[sums2[i]]++;
        }
    }
    void add(int index, int val) {
        cnt[sums2[index]]--;
        this->sums2[index]+=val;
        cnt[sums2[index]]++;
    }
    int count(int tot) {
        int ans=0;
        for(int i:sums1){
            int last=tot-i;
            if(cnt.find(last)!=cnt.end()){
                ans+=cnt[last];
            }
        }
        return ans;
    }
    vector<int>sums1;
    vector<int>sums2;
    unordered_map<int,int>cnt;
};