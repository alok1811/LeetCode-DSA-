1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode *head) {
12        if(head == NULL) return false;
13
14        ListNode* temp = head;
15        ListNode* slow = temp;
16        ListNode* fast = temp;
17
18        while(fast != NULL && fast->next != NULL){
19            slow = slow->next;
20            fast = fast->next->next;
21
22            if(slow == fast) return true;
23        }
24        return false;
25    }
26};