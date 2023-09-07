
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> s;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int le = left;
        while(--left){  // traversing to left
            temp1 = temp1->next;
        }
        while(--right){  // traversing to right
            temp2 = temp2->next;
        }
        while(temp1 != temp2->next){  //pushing nodes->val to stack
            s.push(temp1->val);
            temp1 = temp1->next;
        }
        temp1 = head;
        while(--le){   //again traversing to left
            temp1 = temp1->next;
        }
        while(s.size()){   //from left keep changing nodes->val to s.top()
            temp1->val = s.top();
            temp1 = temp1->next;
            s.pop();
        }
        return head;
    }
};
