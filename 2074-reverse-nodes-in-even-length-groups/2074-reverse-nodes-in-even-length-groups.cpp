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
    
    void reverse(ListNode* head) {
        
        ListNode *prev = NULL, *cur = head;
        while(cur != NULL) {
            auto next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
    }
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        ListNode *ptr = head;
        ListNode *prev = NULL;
        for(int group = 1;ptr != NULL; group++) {
            
            ListNode* start = ptr;
            ListNode* end = ptr;
            int actualLen = 0;
            int expectedLen = group;
            while(expectedLen > 0 and ptr) { 
                end = ptr;
                ptr = ptr -> next;
                actualLen++;
                expectedLen--;
            }
            if(actualLen % 2 == 0) {
                // reverse prev [start,end] ptr
                end -> next = NULL;
                reverse(start);
                if(prev)
                    prev -> next = end;
                else
                    head = end;
                start -> next = ptr;
                prev = start;
            } else {
                prev = end;
            }
        }
        return head;
    }
};