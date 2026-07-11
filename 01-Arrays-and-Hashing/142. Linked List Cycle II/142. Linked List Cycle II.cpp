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
11    ListNode *detectCycle(ListNode *head) {
12
13        ListNode* temp = head;
14        ListNode* slow = temp;
15        ListNode* fast = temp;
16
17        if(temp == NULL) return temp;
18
19        while(fast != NULL && fast->next != NULL){
20            slow= slow->next;
21            fast = fast->next->next;
22
23            if(slow == fast){
24                slow = head;
25
26                while(slow != fast){
27                    slow = slow->next;
28                    fast = fast->next;
29                }
30                return slow;
31            }
32        }
33        return NULL;
34    }
35};