
class Solution {
    
    int length(ListNode *head, ListNode *tail) {
        int ans = 1;
        while(head != tail) {
            head = head -> next;
            ans++;
        }
        return ans;
    }
    
    ListNode* getIntersection(ListNode* head1, int len1, ListNode* head2, int len2) {
        
        while(len1 > len2) {
            head1 = head1 -> next;
            len1--;
        }
        
        while(len2 > len1) {
            head2 = head2 -> next;
            len2--;
        }
        
        while(head1 != head2) {
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        return head1;
        
        
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        
        while(fast and fast->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) break; // cycle detected
        }
        
        // No cycle
        if(fast == NULL or fast -> next == NULL) {
            return NULL;
        }
        
        ListNode* head1 = head;
        ListNode* head2 = slow -> next;
        
        int len1 = length(head1, slow);
        int len2 = length(head2, slow);
        
        ListNode* ans = getIntersection(head1, len1, head2, len2);
        
        return ans;
    }
};