class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Hashset solution
        // Time : O(N)
        // Space : O(1)
        unordered_set<ListNode*> lookup;
        while(head != NULL) {
            if(lookup.count(head)) break;
            lookup.insert(head);
            head = head -> next;
        }
        return head;
    }
};