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
    ListNode* insertionSortList(ListNode* head) {
        
        if(head == 0) return 0;
        
        head -> next = insertionSortList(head -> next); 

        ListNode* current = head;
        
        while(current -> next != 0 and current -> next -> val < current -> val){
            swap(current -> val, current -> next -> val);
            current = current -> next;
        }
        
        return head;
    }
};