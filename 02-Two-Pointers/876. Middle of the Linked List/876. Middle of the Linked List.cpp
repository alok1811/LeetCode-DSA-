1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* middleNode(ListNode* head) {
14        ListNode* temp = head;
15        ListNode* slow = temp;
16        ListNode* fast = temp;
17
18        if(head == NULL) return slow;
19
20        while(fast != NULL && fast->next != NULL){
21            slow = slow->next;
22            fast = fast->next->next;
23        }
24        return slow;
25    }
26};