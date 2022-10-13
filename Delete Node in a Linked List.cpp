// Approach :1

*node=*node->next;

// Approach :2

void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        *node = *next;
        delete next;
}