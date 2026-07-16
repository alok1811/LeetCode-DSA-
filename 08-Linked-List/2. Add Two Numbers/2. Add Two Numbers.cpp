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
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        ListNode* temp1 = l1;
15        ListNode* temp2 = l2;
16
17        int carry = 0;
18
19        ListNode* head = NULL;
20        ListNode* prev = NULL;
21
22        while(temp1 != NULL || temp2 != NULL){
23            int value = carry;
24
25            if(temp1){
26                value += temp1->val;
27            }
28            if(temp2){
29                value += temp2->val;
30            }
31
32            if(value > 9){
33                carry = value / 10;
34                value = value % 10;
35            }
36            else{
37                carry = 0;
38            }
39
40            ListNode* newNode = new ListNode(value);
41
42            if(head == NULL){
43                head = newNode;
44                prev = newNode;
45            }
46            else{
47                prev->next = newNode;
48                prev = newNode;
49            }
50            if(temp1 != NULL){
51                temp1 = temp1->next;
52            }
53            if(temp2 != NULL){
54                temp2 = temp2->next;
55            }
56        }
57        if(carry == 1){
58            ListNode* newNode = new ListNode(carry);
59            prev->next = newNode;
60            prev = newNode;
61        }
62        return head;
63    }
64};