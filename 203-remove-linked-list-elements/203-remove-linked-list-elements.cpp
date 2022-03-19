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
    ListNode* removeElements(ListNode* head, int val) {
        
        auto start = new ListNode(INT_MIN);
        auto end = start;
        
        while(head != NULL) {
            
            if(head -> val == val) {
                head = head -> next;
                continue;
            }
            
            end -> next = head;
            end = end -> next;
            head = head -> next;
            end -> next = NULL;
            
        }
        
        return start -> next;
    }
};