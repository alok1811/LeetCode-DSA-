<h2><a href="https://leetcode.com/problems/linked-list-cycle">141. Linked List Cycle</a></h2>

<p>Given <code>head</code>, the head of a linked list, determine if the linked list has a cycle in it.</p>

<p>There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the&nbsp;<code>next</code>&nbsp;pointer. Internally, <code>pos</code>&nbsp;is used to denote the index of the node that&nbsp;tail's&nbsp;<code>next</code>&nbsp;pointer is connected to.&nbsp;<strong>Note that&nbsp;<code>pos</code>&nbsp;is not passed as a parameter</strong>.</p>

<p>Return&nbsp;<code>true</code><em> if there is a cycle in the linked list</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="width: 300px; height: 97px; margin-top: 8px; margin-bottom: 8px;">
<pre><strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="width: 141px; height: 74px;">
<pre><strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 0th node.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="width: 45px; height: 45px;">
<pre><strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no cycle in the linked list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> is <code>-1</code> or a <strong>valid index</strong> in the linked-list.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you solve it using <code>O(1)</code> (i.e. constant) memory?</p>


---

# 🛍️ Linked-List-Cycle | Explained

## Approach 1 (Floyd's Tortoise and Hare Algorithm)
### Intuition
The core idea behind this approach is inspired by the fable of the tortoise and the hare. Imagine two racers, one running at a normal speed (the tortoise) and the other running at twice the speed (the hare). If there is a cycle in the track (i.e., the linked list), the hare will eventually catch up to the tortoise because it covers twice the distance. If there is no cycle, the hare will reach the end of the track. This intuition works in detecting a cycle in a linked list because if a cycle exists, the faster pointer will eventually meet the slower pointer within the cycle.

### Approach
The algorithmic breakdown involves the following steps:
1. Initialize two pointers, `slow` and `fast`, both pointing at the head of the linked list.
2. In each iteration, move `slow` one step ahead (`slow = slow->next`) and `fast` two steps ahead (`fast = fast->next->next`).
3. Check if `slow` and `fast` have met (`slow == fast`). If they have, it indicates a cycle in the linked list.
4. If `fast` reaches the end of the linked list (`fast == NULL` or `fast->next == NULL`), it means there is no cycle.

### Detailed Code Analysis
Let's dive into the code:
```cpp
12    bool hasCycle(ListNode *head) {
13        if(head == NULL) return false;
```
The function starts by checking if the `head` of the linked list is `NULL`. If it is, the function immediately returns `false` because an empty list cannot have a cycle.

```cpp
14        ListNode* temp = head;
15        ListNode* slow = temp;
16        ListNode* fast = temp;
```
Here, three pointers are initialized: `temp`, `slow`, and `fast`, all pointing at the `head` of the linked list. The `temp` pointer is not necessary and seems to be redundant; the initialization could directly assign `head` to `slow` and `fast`.

```cpp
18        while(fast != NULL && fast->next != NULL){
```
The loop condition ensures that `fast` and `fast->next` are both not `NULL`, preventing potential null pointer dereferences.

```cpp
19            slow = slow->next;
20            fast = fast->next->next;
21
22            if(slow == fast) return true;
23        }
```
Inside the loop, `slow` moves one step forward, and `fast` moves two steps forward. After updating the positions, the code checks if `slow` and `fast` have met. If they have, it means a cycle is present, and the function returns `true`.

```cpp
24        return false;
25    }
```
If the loop completes without finding a cycle (i.e., `fast` reaches the end of the list), the function returns `false`, indicating no cycle is present.

### Code
```cpp
12    bool hasCycle(ListNode *head) {
13        if(head == NULL) return false;
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
```
### Complexity
- Time: The time complexity of this solution is O(n), where n is the number of nodes in the linked list. In the worst case, the fast pointer travels through the entire list.
- Space: The space complexity is O(1), meaning the space used does not grow with the size of the input linked list, as only a constant amount of space is used to store the pointers.

## 🕵️‍♂️ Follow-up Questions (Optional)
1. **How would you handle the case where the cycle is very large?** - The Floyd's Tortoise and Hare algorithm can still detect the cycle efficiently, regardless of its size, because it relies on the relative speed of the two pointers, not the absolute size of the cycle.
2. **Can you modify the algorithm to find the start of the cycle?** - Yes, after detecting the cycle, you can reset one of the pointers to the head of the list and keep the other pointer at the meeting point. Then, move both pointers one step at a time. The point where they meet again is the start of the cycle.