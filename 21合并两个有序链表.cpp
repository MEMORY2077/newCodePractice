#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*head=nullptr;
        ListNode*tail=nullptr;
        ListNode*p=list1;
        ListNode*q=list2;
        while(p!=nullptr&&q!=nullptr){
            ListNode*temp;
            if(p->val<q->val){
                temp=p;
                p=p->next;
                temp->next=nullptr;
            }
            else{
                temp=q;
                q=q->next;
                temp->next=nullptr;
            }
            if(head==nullptr){
                head=temp;
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=tail->next;
            }
        }
        if(p){
            if(head==nullptr){
                head=p;
                tail=p;
            }
            else tail->next=p;
        }
        if(q){
            if(head==nullptr){
                head=q;
                tail=q;
            }
            else tail->next=q;
        }
        return head;
    }
};