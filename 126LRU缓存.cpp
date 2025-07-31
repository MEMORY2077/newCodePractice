#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
    int val;
    int key;
    Node*left;
    Node*right;
    Node(int key,int val){
        this->val=val;
        this->key=key;
        this->left=this;
        this->right=this;
    }
    Node(int key,int val,Node* anon){
        this->key=key;
        this->val=val;
        this->left=anon;
        this->right=anon->right;
        anon->right->left=this;
        anon->right=this;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
    }
    
    int get(int key) {
        if(map.find(key)==map.end())return -1;
        Node*G=map[key];
        G->left->right=G->right;
        G->right->left=G->left;
        G->right=head->right;
        G->left=head;
        head->right=G;
        G->right->left=G;
        return G->val;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            Node*G=map[key];
            G->val=value;
            G->left->right=G->right;
            G->right->left=G->left;
            G->right=head->right;
            G->left=head;
            head->right=G;
            G->right->left=G;
            return;
        }
        Node*G=new Node(key,value,head);
        map.emplace(key,G);
        if(map.size()>capacity){
            map.erase(head->left->key);
            head->left=head->left->left;
            head->left->right=head;
        }
    }
private:
    int capacity=0;
    Node*head=nullptr;
    unordered_map<int,Node*>map;
};