<h2><a href="https://leetcode.com/problems/add-two-numbers">2. Add Two Numbers</a></h2>

<p>You are given two <strong>non-empty</strong> linked lists representing two non-negative integers. The digits are stored in <strong>reverse order</strong>, and each of their nodes contains a single digit. Add the two numbers and return the sum&nbsp;as a linked list.</p>

<p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg" style="width: 483px; height: 342px;">
<pre><strong>Input:</strong> l1 = [2,4,3], l2 = [5,6,4]
<strong>Output:</strong> [7,0,8]
<strong>Explanation:</strong> 342 + 465 = 807.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> l1 = [0], l2 = [0]
<strong>Output:</strong> [0]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
<strong>Output:</strong> [8,9,9,9,0,0,0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each linked list is in the range <code>[1, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
	<li>It is guaranteed that the list represents a number that does not have leading zeros.</li>
</ul>


---

# 🛍️ Add-Two-Numbers | Explained

## Approach 1 (Iterative)
### Intuition
The idea behind this approach is to simulate the process of adding two numbers manually, where we start from the least significant digit and move towards the most significant digit, handling any carry-over values as we go. This approach works because it allows us to efficiently process the digits of the two input numbers in a single pass, while also keeping track of any carry-over values that need to be propagated to the next digit.

### Approach
The approach can be broken down into the following steps:

1. Initialize pointers to the heads of the two input linked lists, `l1` and `l2`.
2. Initialize a `carry` variable to keep track of any carry-over values.
3. Initialize a `head` pointer to the head of the result linked list, as well as a `prev` pointer to keep track of the previous node in the result linked list.
4. Iterate through the input linked lists, processing one node at a time.
5. For each node, calculate the sum of the current values of `l1` and `l2`, plus any carry-over value.
6. If the sum is greater than 9, update the `carry` variable and calculate the new value for the current node.
7. Create a new node with the calculated value and add it to the result linked list.
8. Repeat steps 4-7 until all nodes in both input linked lists have been processed.
9. If there is still a carry-over value after processing all nodes, create a new node with the carry-over value and add it to the result linked list.

### Detailed Code Analysis
Let's take a closer look at the code:

```cpp
ListNode* temp1 = l1;
ListNode* temp2 = l2;
```

These two lines initialize the `temp1` and `temp2` pointers to the heads of the two input linked lists, `l1` and `l2`.

```cpp
int carry = 0;
ListNode* head = NULL;
ListNode* prev = NULL;
```

These three lines initialize the `carry` variable to 0, as well as the `head` and `prev` pointers to NULL. The `head` pointer will be used to keep track of the head of the result linked list, while the `prev` pointer will be used to keep track of the previous node in the result linked list.

```cpp
while(temp1 != NULL || temp2 != NULL){
    int value = carry;
    if(temp1){
        value += temp1->val;
    }
    if(temp2){
        value += temp2->val;
    }
```

This loop will continue until all nodes in both input linked lists have been processed. Inside the loop, we calculate the sum of the current values of `l1` and `l2`, plus any carry-over value.

```cpp
if(value > 9){
    carry = value / 10;
    value = value % 10;
} else {
    carry = 0;
}
```

If the sum is greater than 9, we update the `carry` variable and calculate the new value for the current node.

```cpp
ListNode* newNode = new ListNode(value);
if(head == NULL){
    head = newNode;
    prev = newNode;
} else {
    prev->next = newNode;
    prev = newNode;
}
```

We create a new node with the calculated value and add it to the result linked list. If this is the first node in the result linked list, we update the `head` pointer to point to the new node. Otherwise, we update the `next` pointer of the previous node to point to the new node.

```cpp
if(temp1 != NULL){
    temp1 = temp1->next;
}
if(temp2 != NULL){
    temp2 = temp2->next;
}
```

Finally, we move the `temp1` and `temp2` pointers to the next nodes in the input linked lists.

```cpp
if(carry == 1){
    ListNode* newNode = new ListNode(carry);
    prev->next = newNode;
    prev = newNode;
}
```

After the loop, we check if there is still a carry-over value. If there is, we create a new node with the carry-over value and add it to the result linked list.

### Code
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;

    int carry = 0;

    ListNode* head = NULL;
    ListNode* prev = NULL;

    while(temp1 != NULL || temp2 != NULL){
        int value = carry;
        if(temp1){
            value += temp1->val;
        }
        if(temp2){
            value += temp2->val;
        }

        if(value > 9){
            carry = value / 10;
            value = value % 10;
        } else {
            carry = 0;
        }

        ListNode* newNode = new ListNode(value);

        if(head == NULL){
            head = newNode;
            prev = newNode;
        } else {
            prev->next = newNode;
            prev = newNode;
        }

        if(temp1 != NULL){
            temp1 = temp1->next;
        }
        if(temp2 != NULL){
            temp2 = temp2->next;
        }
    }

    if(carry == 1){
        ListNode* newNode = new ListNode(carry);
        prev->next = newNode;
        prev = newNode;
    }

    return head;
}
```

### Complexity
- Time: O(max(m, n)), where m and n are the lengths of the input linked lists. This is because we process each node in the input linked lists once.
- Space: O(max(m, n)), where m and n are the lengths of the input linked lists. This is because in the worst case, we may need to create a new linked list with a length equal to the maximum of m and n.

## 🕵️‍♂️ Follow-up Questions
Some common follow-up questions for this problem are:
* How would you handle the case where the input linked lists have different lengths?
* Can you optimize the space complexity of the solution?
The answers to these questions are:
* The solution already handles the case where the input linked lists have different lengths, by using the `while` loop condition `temp1 != NULL || temp2 != NULL`. This ensures that we process all nodes in both input linked lists, even if one list is longer than the other.
* The space complexity of the solution is already optimized, with a time complexity of O(max(m, n)) and a space complexity of O(max(m, n)). However, we could potentially optimize the solution further by using a more efficient data structure, such as a vector or array, to store the result.