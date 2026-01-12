#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        int canBeTypedWords(string text, string brokenLetters) {
            stringstream strin(text);
            unordered_set<char>broken(brokenLetters.begin(),brokenLetters.end());
            string now;
            int ans=0;
            while(strin>>now){
                ans++;
                for(char letter:now){
                    if(broken.find(letter)!=broken.end()){
                        ans--;
                        break;
                    }
                }
            }
            return ans;
        }
    };