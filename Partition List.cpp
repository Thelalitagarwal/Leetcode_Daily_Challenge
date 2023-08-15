/*
Link to the "Partition List " Problem ==>> https://leetcode.com/problems/partition-list/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/q6KzSWv5L-s

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
    ListNode* partition(ListNode* head, int x) {

        ListNode* first = new ListNode();

        ListNode* curFirst = first;

        ListNode* second = new ListNode();

        ListNode* curSecond = second;
        
        while(head) {
            if(head->val < x) {
                curFirst->next = new ListNode(head->val);
                curFirst = curFirst->next;
            }
            else {
                curSecond->next = new ListNode(head->val);
                curSecond = curSecond->next;
            }
            head = head->next;
        }
        curFirst->next = second->next;
        return first->next;
    }
};