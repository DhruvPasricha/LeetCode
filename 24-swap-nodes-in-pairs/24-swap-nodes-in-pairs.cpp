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
        
        // inserting dummy head node         
        ListNode* dummyHead = new ListNode(-1);
        dummyHead -> next = head;
        
        ListNode* prevNode = dummyHead;
        ListNode* firstNode = head;
        
        while(firstNode and firstNode -> next) {
            
            // storing secondNode
            auto secondNode = firstNode -> next;
            
            // updating links             
            prevNode -> next = secondNode;
            firstNode -> next = secondNode -> next;
            secondNode -> next = firstNode;
            
            // updating for next iteration            
            prevNode = firstNode;
            firstNode = firstNode -> next;
        }
        
        head = dummyHead -> next;
        
        return head;
                
    }
};