#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            unordered_set<string>have;
            queue<string>q;
            unordered_set<string>dict(bank.begin(),bank.end());
            vector<char>part={'A','C','G','T'};
            int step=0;
            dict.emplace(startGene);
            have.emplace(startGene);
            if(startGene==endGene)return 0;
            if(dict.find(endGene)==dict.end())return -1;
            q.push(startGene);
            while(!q.empty()){
                int sz=q.size();
                for(int _=0;_<sz;_++){
                    string now=q.front();
                    q.pop();
                    if(now==endGene)return step;
                    for(int i=0;i<8;i++){
                        //if(now[i]!=endGene[i]){
                        for(char ch:part){
                            if(ch!=now[i]){
                                string next=now;
                                next[i]=ch;
                                if(dict.find(next)!=dict.end()&&have.find(next)==have.end()){//合法且没用过
                                    have.emplace(next);
                                    q.push(next);
                                }
                            }
                        }
                        //}
                    }
                }
                step++;
            }
            return -1;
        }
    };