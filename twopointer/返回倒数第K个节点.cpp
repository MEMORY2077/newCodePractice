struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode*p=head;
        ListNode*q=head;
        for (int i=0;i<k;i++){
            q=q->next;
        }
        while(q!=nullptr){
            p=p->next;
            q=q->next;
        }
        return p->val;
    }
};