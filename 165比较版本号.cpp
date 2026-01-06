#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream vs1(version1);
        stringstream vs2(version2);
        vector<int>Vs1;
        vector<int>Vs2;
        char rubbish;
        int i=0;
        do{
            int k=0;
            vs1>>k;
            Vs1.push_back(k);
        }while(vs1>>rubbish);
        i=0;
        do{
            int k=0;
            vs2>>k;
            Vs2.push_back(k);
        }while(vs2>>rubbish);
        //int m=min(Vs1.size(),Vs2.size());
        if(Vs1.size()>Vs2.size()){
            int m=Vs1.size()-Vs2.size();
            for(int i=0;i<m;i++){
                Vs2.insert(Vs2.begin(),0);
            }
        }
        else{
            int m=Vs2.size()-Vs1.size();
            for(int i=0;i<m;i++){
                Vs1.insert(Vs1.begin(),0);
            }            
        }
        for(int i=0;i<Vs1.size();i++){
            if(Vs1[i]>Vs2[i])return 1;
            if(Vs1[i]<Vs2[i])return -1;
        }
        return 0;
    }
};