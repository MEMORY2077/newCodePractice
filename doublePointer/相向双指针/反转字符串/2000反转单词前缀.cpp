#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int e=0;
        int n=word.size();
        for(e;e<n;e++){
            if(word[e]==ch)break;
        }
        if(e==n)return word;
        for(int i=0,j=e;i<j;i++,j--){
            char temp=word[i];
            word[i]=word[j];
            word[j]=temp;
        }
        return word;
    }
};