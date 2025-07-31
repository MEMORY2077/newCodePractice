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
    bool isPalindrome(ListNode* head) {
        ListNode*p=head;
        ListNode*q=head;
        while(q!=nullptr&&q->next!=nullptr){
            q=q->next->next;
            p=p->next;
        }
        ListNode*head2=p;
        while(p->next!=nullptr){
            q=p->next;
            p->next=q->next;
            q->next=head2;
            head2=q;
        }
        p=head;
        q=head2;
        while(q!=nullptr){
            if(p->val!=q->val)return false;
            p=p->next;
            q=q->next;
        }
        return true;
    }
};