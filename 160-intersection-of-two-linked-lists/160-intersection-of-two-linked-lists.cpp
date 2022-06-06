/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> st1, st2;
        
        while(headA != NULL)  {
            st1.push(headA);
            headA = headA -> next;
        }
        
         while(headB != NULL)  {
            st2.push(headB);
            headB = headB -> next;
        }
        
        ListNode* prev = NULL;
        
        while(st1.size() and st2.size() and st1.top() == st2.top()) {
            prev = st1.top();
            st1.pop();
            st2.pop();
        }
        
        return prev;
    }
};