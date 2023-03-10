/*
Link to the " Linked List Random Node " Problem ==>>  https://leetcode.com/problems/linked-list-random-node/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/qQDM1J02Sq4

*/

class Solution {
public:
    ListNode *head = NULL;
    
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int ans = 0, i = 1;
        ListNode *p = this->head;
        while (p) {
            if (rand() % i == 0) 
                ans = p->val;
            i++;
            p = p->next;
        }
        return ans;
    }
};