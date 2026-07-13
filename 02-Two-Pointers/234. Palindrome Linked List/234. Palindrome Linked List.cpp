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
24    bool isPalindrome(ListNode* head) {
25        if(head == NULL || head->next == NULL){
26            return true;
27        }
28        ListNode* fast = head;
29        ListNode* slow = head;
30        while(fast->next != NULL && fast->next->next != NULL){
31            slow = slow->next;
32            fast = fast->next->next;
33        }
34        ListNode* newhead = reverse(slow->next);
35        ListNode* first = head;
36        ListNode* second = newhead;
37        while(second != NULL){
38            if(first->val != second->val){
39                // reverse(newhead);
40                return false;
41            }
42            first = first->next;
43            second = second->next;
44        }
45        // reverse(newhead);
46        return true;
47    }
48};