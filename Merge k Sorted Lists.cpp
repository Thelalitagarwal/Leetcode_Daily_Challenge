/*
Link to the " Merge k Sorted Lists " Problem ==>>  https://leetcode.com/problems/merge-k-sorted-lists/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/7wdont5Bgnk

*/

class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {

        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode*head;
        if(l1->val<=l2->val){
            head=l1;
        }
        else{
            head=l2;
        } 
        if(l1->val<=l2->val){
           head->next = merge2Lists(l1->next, l2);
        }
        else{
           head->next = merge2Lists(l1, l2->next);
        }
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) 
            return NULL;
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++)
            head = merge2Lists(head, lists[i]);
        
        return head;
    }
};