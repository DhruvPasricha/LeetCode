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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        auto head = new ListNode(INT_MIN);
        auto tail = head;
        
        while(list1 or list2) {
            auto &cur = (list2 == NULL or (list1 != NULL and list1 -> val <= list2 -> val)) ? list1 : list2; 
            tail -> next = cur;
            cur = cur -> next;
            tail = tail -> next;
        }
        
        return head -> next;
    }
};