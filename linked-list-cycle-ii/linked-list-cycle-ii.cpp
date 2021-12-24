class Solution {
    
    
    int length(ListNode* head, ListNode *tail) {
        
        int ans = 0;
        while(head != tail) {
            ans++;
            head = head -> next;
        }
        return ans + 1;
    }
    
    ListNode *intersection(ListNode *head1, ListNode *head2, int len1, int len2) {
        
        if(len1 < len2) return intersection(head2, head1, len2, len1);
        
        while(len1 > len2) head1 = head1 -> next, len1--;
        
        while(head1 != head2) {
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        return head1;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        // Slow and Fast Pointer Solution
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL and fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) break;
        }
        
        // No cycle
        if(fast == NULL or fast -> next == NULL) return NULL;
        
        // Cycle exists
        ListNode* tail = slow;
        
        ListNode* head1 = head;
        ListNode* head2 = tail -> next;
        
        int len1 = length(head1, tail);
        int len2 = length(head2, tail);
        
        return intersection(head1, head2, len1, len2);    
    }
};