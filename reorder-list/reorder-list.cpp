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
private:
    pair<ListNode*, ListNode*> split(ListNode *head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        
        while(fast != NULL and fast -> next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if(prev != NULL) {
            prev -> next = NULL;
        }
        return {head, slow};
        
    }
    
    ListNode* reverse(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *current = head;
        
        while(current != NULL) {
            ListNode *next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    
    void insert(ListNode *&head, ListNode *&tail, ListNode *&current) {
        
        if(current == NULL) return;
        if(head == NULL) {
            head = current;
        } else {
            tail -> next = current;
        }
        tail = current;
        current = current -> next;
    }
    
    ListNode* mergeAlternatively(ListNode* head1, ListNode* head2) {
        
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        bool odd = true;
        while(head1 != NULL or head2 != NULL) {
            
            if(odd) {
                insert(head, tail, head1);
            } else {
                insert(head, tail, head2);
            }
            
            odd = not odd;
            
        }
        
        return head;
    }
    
public:

    void reorderList(ListNode* head) {
        
        if(head == NULL or head -> next == NULL) return;
        
        auto twoParts = split(head);
        
        auto firstPart = twoParts.first;
        auto secondPart = twoParts.second;
        

        secondPart = reverse(secondPart);

        head = mergeAlternatively(firstPart, secondPart);
    }
};