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
    bool hasCycle(ListNode *head) {
        ListNode*p=head;
        ListNode*q=head;
        while(q!=nullptr&&q->next!=nullptr){
            q=q->next->next;
            p=p->next;
            if(p==q)return true;
        }
        return false;
    }
};