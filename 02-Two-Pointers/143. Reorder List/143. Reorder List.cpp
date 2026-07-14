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
13    ListNode* reverse(ListNode* head){
14        ListNode* temp = head;
15        ListNode* prev = NULL;
16        while(temp != NULL){
17            ListNode* front = temp->next;
18            temp->next = prev;
19            prev = temp;
20            temp = front;
21        }
22        return prev;
23    }
24    void reorderList(ListNode* head) {
25        ListNode* slow = head;
26        ListNode* fast = head;
27
28        while(fast->next != NULL && fast->next->next != NULL){
29            slow = slow->next;
30            fast = fast->next->next;
31        }
32        ListNode* newHead = reverse(slow->next);
33        slow->next = NULL;
34        ListNode* first = head;
35        ListNode* second = newHead;
36
37        while(second != NULL){
38            ListNode* firstNext = first->next;
39            ListNode* secondNext = second->next;
40
41            first->next = second;
42            second->next = firstNext;
43
44            first = firstNext;
45            second = secondNext;
46        }
47        return;
48    }
49};