#include <unordered_map>
#include <vector>
#include <random>
#include <time.h>
using namespace std;
// 为什么不单独用vector或unordered_map🤔
//vector:没有办法在O(1)时间确定某一个元素是否在数组里
//unordered_map:哈希表不是均匀分布的也就没办法在O(1)时间内给出一个真的随机数
class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(index.find(val)!=index.end())return false;
        int i=nums.size();
        nums.push_back(val);
        index[val]=i;
        return true;
    }
    
    bool remove(int val) {
        if(index.find(val)==index.end())return false;
        int temp=nums.back();
        int i=index[val];
        nums[i]=temp;
        index[temp]=i;
        nums.pop_back();
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        int f=rand()%(nums.size());
        return nums[f];
    }
private:
    vector<int>nums;
    unordered_map<int,int>index;
};
