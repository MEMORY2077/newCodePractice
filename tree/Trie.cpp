#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
struct Tree{
    unordered_map<char,Tree*>next;
    bool end=false;
};
class Trie {
public:
    Trie() {
        head=new Tree();
    }
    
    void insert(string word) {
        Tree* p=head;
        for(auto now:word){
            if(p->next.find(now)==p->next.end()){
                p->next[now]=new Tree();
            }
            p=p->next[now];
        }
        p->end=true;
    }
    
    bool search(string word) {
        Tree*p=head;
        for(auto now:word){
            if(p->next.find(now)==p->next.end()){
                return false;
            }
            p=p->next[now];
        }
        if(p->end)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Tree*p=head;
        for(auto now:prefix){
            if(p->next.find(now)==p->next.end()){
                return false;
            }
            p=p->next[now];
        }
        return true;
    }
    Tree* head=nullptr;
};
int main(void){
    Trie*obj=new Trie();
    vector<string>test={"Trie","insert","search","search","startsWith","insert","search"};
        obj->insert("apple");
        bool ans=obj->search("apple");

        return 0;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */