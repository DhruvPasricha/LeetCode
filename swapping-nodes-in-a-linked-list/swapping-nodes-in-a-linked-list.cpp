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
    
    ListNode* getkthNodeFront(ListNode *head, int k) {
        
        for(int i = 1;i <= k - 1; i++) {
            head = head -> next;
        }
        return head;
    }
    
    ListNode* getkthNodeRear(ListNode *head, int k) {
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        
        for(int i = 1;i <= k;i++) {
            ptr2 = ptr2 -> next;
        }
        
        while(ptr2 != NULL) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        return ptr1;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        
        auto kthNodeLeft = getkthNodeFront(head, k);
        auto kthNodeRight = getkthNodeRear(head, k);
        
        swap(kthNodeLeft->val, kthNodeRight->val);
        
        return head;
    }
};