/*
Link to the " Add Two Numbers II " Problem ==>> https://leetcode.com/problems/add-two-numbers-ii/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/KXYeNut_2W0

*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry > 0) {
            int sum = 0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum % 10);
            curr -> next = node;
            curr = curr ->next;
        }
        ans = reverseList(ans->next);
        return ans;
    }
};