/*
Link to the " Linked List Cycle II " Problem ==>>  https://leetcode.com/problems/linked-list-cycle-ii/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/owc1yVJOklw

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slw,*fst;
        slw=fst=head;
        while(fst && fst->next){
            slw = slw->next;
            fst = fst->next->next;
            if(fst==slw)break;
        }
        if(!fst || !fst->next)
            return NULL;
        fst=head;
        while(fst!=slw){
            fst=fst->next;
            slw=slw->next;
        }
        return fst;
    }
};