#include <iostream>
#include "list.h"
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)return nullptr;
        ListNode*fakehead=new ListNode(-1);
        fakehead->next=head;
        ListNode*p=fakehead;
        ListNode*q;
        q=p;
        while(1){
            for(int _;_<k;_++){
                if(q==nullptr){
                    return fakehead->next;
                }
                q=q->next;
            }
            ListNode*piece=p;
            p=p->next;
            for(int _;_<k-1;_++){
                q=p->next;
                p->next=q->next;
                q->next=piece->next;
                piece->next=q;
            }

        }
    }
};