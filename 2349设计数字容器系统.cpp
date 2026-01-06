#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class NumberContainers {
    public:
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if(index2num.find(index)!=index2num.end()){
                num2index[index2num[index]].erase(index);
            }
            index2num[index]=number;
            num2index[number].insert(index);
        }
        
        int find(int number) {
            auto result=num2index.find(number);
            if(result==num2index.end()){
                return -1;
            }
            return *result->second.begin();
        }
        unordered_map<int,int>index2num;
        unordered_map<int,set<int>>num2index;
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */