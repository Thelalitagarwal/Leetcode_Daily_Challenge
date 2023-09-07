link to the problem: https://leetcode.com/problems/reverse-linked-list-ii/?envType=daily-question&envId=2023-09-07

link to the solution: https://www.youtube.com/watch?v=71eUmoZtcHo

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) 
            return nullptr;

        ListNode* dummy = new ListNode(0,head);
        head = dummy;
        ListNode* curr = head->next;
        ListNode* prev = dummy;

        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* left_prev = prev->next;

        for(int i=0; i< right - left;i++){

            ListNode* temp = prev->next;
            prev->next = left_prev->next;

            left_prev->next = left_prev->next->next;
            
            prev->next->next = temp; 
        }
        return dummy->next;
    }
};
