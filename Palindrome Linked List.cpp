class Solution {
public:
   void reverseLinkedList(ListNode* &head)
    {
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next;
            if(fast->next!=NULL)
                fast=fast->next;
            slow=slow->next;
        }
        ListNode* nextHalf=slow->next;
        slow->next=NULL;
        reverseLinkedList(nextHalf);
        ListNode* start=head;
        bool flag=true;
        while(nextHalf!=NULL&&start!=NULL)
        {
            if(nextHalf->val!=start->val)
                flag=false;
            nextHalf=nextHalf->next;
            start=start->next;
        }
        return flag;
    }
};