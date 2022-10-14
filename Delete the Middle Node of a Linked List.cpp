class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)return NULL;
        ListNode*slow=head,*fast=head->next->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow->next->next)
        slow->next=slow->next->next;
        else
        slow->next=NULL;
        return head;
    }
};