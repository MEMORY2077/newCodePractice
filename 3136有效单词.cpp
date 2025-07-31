#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        int aeiou=0;
        int num=0;
        for(auto i:word){
            if(!((i>='0'&&i<='9')||(i>='a'&&i<='z')||i>='A'&&i<='Z'))return false;
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='A'||i=='E'||i=='I'||i=='O'||i=='U')aeiou++;
            if(i>='0'&&i<='9')num++;
        }
        if(aeiou==0||(aeiou+num)==word.size())return false;
        return true;
    }
};