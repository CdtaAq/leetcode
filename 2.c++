class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* dum = new ListNode(-1);
        ListNode* cu = dum;
        while(l1 or l2 or c)
        {
            int va = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;        c = va/10;
            va = va%10;
            dum->next = new ListNode(va);
            dum = dum->next;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        return cu->next;
    }
};
