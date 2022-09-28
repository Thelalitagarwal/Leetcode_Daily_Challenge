class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        else if(head->next==NULL) return NULL;
        ListNode* temp = head;
        int size=0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        temp=head;
        if(size==n){
            head=head->next;
            return head;
        } 
        for(int i=0;i<size-n-1;i++){ 
            temp=temp->next;
        }
        if(temp->next->next)
            temp->next = temp->next->next;
        else if(temp->next)
            temp->next=NULL;
      
        return head;
    }
};