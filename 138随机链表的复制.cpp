#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*newhead=nullptr;
        Node*p=head;
        Node*q;
        while(p!=nullptr){
            Node*temp=new Node(p->val);
            if(newhead==nullptr){
                newhead=temp;
                q=newhead;
                p=p->next;
            }
            else{
                q->next=temp;
                p=p->next;
                q=q->next;
            }
        }
        while(p){
            cout<<p->val<<' ';
            if(p->random==nullptr)cout<<'0'<<endl;
            else cout<<p->random->val<<endl;
            p=p->next;
        }
        p=head;
        Node *np=newhead;
        while(p){
            q=p->random;
            if(q==nullptr){
                np->random=nullptr;
                p=p->next;
                np=np->next;
                continue;
            }
            Node*rq=head;
            Node*nrq=newhead;
            while(rq!=q){
                rq=rq->next;
                nrq=nrq->next;
            }
            np->random=nrq;
            p=p->next;
            np=np->next;
        }
        /*while(head!=nullptr){
            cout<<head->val<<' ';
            head=head->next;
        }
        */
        cout<<endl;
        p=newhead;
        while(p){
            cout<<p->val<<' ';
            if(p->random==nullptr)cout<<'0'<<endl;
            else cout<<p->random->val<<endl;
            p=p->next;
        }
        cout<<endl;
        return newhead;
    }
};