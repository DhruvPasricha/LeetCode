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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL or head -> next == NULL)
            return head;
        
        auto third = swapPairs(head -> next -> next);
        
        auto first = head -> next;
        auto second = head;
        
        first -> next = second;
        second -> next = third;
        
        return first;
    }
};