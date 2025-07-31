#include <iostream>
#include "list.h"
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr||head->next==nullptr)return head->next;
        ListNode*fakehead=new ListNode(-1,head);
        ListNode*p=fakehead;
        ListNode*q=fakehead;
        int k=n;
        while(k>0){
            q=q->next;
            k--;
        }
        while(q!=nullptr&&q->next!=nullptr){
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return fakehead->next;
    }
};