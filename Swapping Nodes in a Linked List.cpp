/*
Link to the " Swapping Nodes in a Linked List " Problem ==>> https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/PzACfONxUco

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* front = head;

        while(--k){
            front = front->next;
        }

        ListNode* ahead = front;
        ListNode* back = head;

        while(ahead->next){

            ahead = ahead->next;
            
            back = back->next;
        }
        swap(front->val,back->val);
        return head;
    }
};