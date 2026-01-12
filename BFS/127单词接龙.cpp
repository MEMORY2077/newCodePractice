#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string next="abcdefghijklmnopqrstuvwxyz";
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            queue<string>q;
            unordered_set<string>used;
            unordered_set<string>dict(wordList.begin(),wordList.end());
            if(dict.count(endWord)==0)return 0;
            int step=0;
            q.push(beginWord);
            used.emplace(beginWord);
            while(!q.empty()){
                int sz=q.size();
                for(int _=0;_<sz;_++){
                    string now=q.front();
                    q.pop();
                    int s=now.size();
                    for(int i=0;i<s;i++){
                        for(char ne:next){
                            string nex=now;
                            nex[i]=ne;
                            if(nex==endWord)return step;
                            if(nex!=now&&!used.count(nex)&&dict.count(nex)){
                                q.push(nex);
                                used.emplace(nex);
                            }
                        }
                    }
                }
                step++;
            }
            return 0;
        }
    };