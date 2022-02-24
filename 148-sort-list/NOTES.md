# Solution 1: Merge Sort
​
```
class Sorting{
ListNode* merge(ListNode* head1, ListNode* head2) {
ListNode *head = new ListNode(0); // dummy head node
ListNode *tail = head;
while(head1 and head2) {
auto &current = (head1 -> val <= head2 -> val) ? head1 : head2;
tail -> next = current;
tail = tail -> next;
current = current -> next;
}
if(head1)
tail -> next = head1;