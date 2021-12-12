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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int i = 0;
        ListNode* prev = NULL, *cur = list1;

        while(i < a){
            prev = cur;
            i++;
            cur = cur -> next;
        }
        // prev -> a - 1

        while(cur != NULL and i < b + 1){
            i++;
            cur = cur -> next;
        }
        
        prev -> next = list2;
        
        prev = list2;
        
        while(list2 != NULL){
            prev = list2;
            list2 = list2 -> next; 
        }
        prev -> next = cur;
        
        return list1;
    }
};

// 0 1 2 3 4 ...  a - 1  a ........... b b + 1 ..........
    