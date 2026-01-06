#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Router {
public:
    Router(int memoryLimit) {
        Limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int>packet(source,destination,timestamp);
        if(ms.find(packet)!=ms.end()){
            return false;
        }
        ms.emplace(packet);
        if(dq.size()>=Limit){
            auto rub=dq.begin();
            forwardPacket();
        }
        dq.push_back(packet);
        sameDestQ[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int>data;
        if(!dq.empty()){
            auto packet=dq.front();
            data=vector<int>{get<0>(packet),get<1>(packet),get<2>(packet)};
            ms.erase(packet);
            dq.pop_front();
            sameDestQ[data[1]].pop_front();
        }
        return data;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto pos1=lower_bound(sameDestQ[destination].begin(),sameDestQ[destination].end(),startTime);
        auto pos2=upper_bound(sameDestQ[destination].begin(),sameDestQ[destination].end(),endTime);
        return pos2-pos1;
    }
    deque<tuple<int,int,int>>dq;
    set<tuple<int,int,int>>ms;
    int Limit;
    unordered_map<int,deque<int>>sameDestQ;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */