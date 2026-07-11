<h2><a href="https://leetcode.com/problems/linked-list-cycle-ii">142. Linked List Cycle II</a></h2>

<p>Given the <code>head</code> of a linked list, return <em>the node where the cycle begins. If there is no cycle, return </em><code>null</code>.</p>

<p>There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the <code>next</code> pointer. Internally, <code>pos</code> is used to denote the index of the node that tail's <code>next</code> pointer is connected to (<strong>0-indexed</strong>). It is <code>-1</code> if there is no cycle. <strong>Note that</strong> <code>pos</code> <strong>is not passed as a parameter</strong>.</p>

<p><strong>Do not modify</strong> the linked list.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="height: 145px; width: 450px;">
<pre><strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> tail connects to node index 1
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the second node.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 105px; width: 201px;">
<pre><strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> tail connects to node index 0
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the first node.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 65px; width: 65px;">
<pre><strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> no cycle
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

# 🛍️ Linked-List-Cycle-II | Explained

## Approach 1 (Optimized)
### Intuition
The core idea behind this approach is to use the "tortoise and hare" algorithm, also known as Floyd's cycle-finding algorithm. Imagine two people racing on a circular track. The tortoise moves one step at a time, while the hare moves two steps at a time. If there is a cycle in the track, the hare will eventually catch up to the tortoise within the cycle. This approach works because the faster pointer (hare) will eventually meet the slower pointer (tortoise) if a cycle exists.

### Approach
The algorithmic breakdown is as follows:
1. Initialize two pointers, `slow` and `fast`, to the head of the linked list.
2. Move the `slow` pointer one step at a time and the `fast` pointer two steps at a time.
3. If a cycle exists, the `fast` pointer will eventually meet the `slow` pointer within the cycle.
4. Once a meeting point is found, reset the `slow` pointer to the head of the linked list and keep the `fast` pointer at the meeting point.
5. Move both pointers one step at a time. The point where they meet again is the start of the cycle.

### Detailed Code Analysis
The code initializes three pointers: `temp`, `slow`, and `fast`, all pointing to the head of the linked list. The `temp` pointer is used to check if the head is `NULL`, in which case the function returns `NULL`. The `slow` and `fast` pointers are then moved in the loop.

```cpp
ListNode* temp = head;
ListNode* slow = temp;
ListNode* fast = temp;
```

The loop checks if the `fast` pointer and its next node are not `NULL`, ensuring that the `fast` pointer doesn't go out of bounds.

```cpp
while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
```

 Inside the loop, the code checks if the `slow` and `fast` pointers have met.

```cpp
if(slow == fast){
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

In this block, the `slow` pointer is reset to the head of the linked list, and both pointers are moved one step at a time until they meet again. This meeting point is the start of the cycle, and the function returns this node.

### Code
```cpp
ListNode *detectCycle(ListNode *head) {
    ListNode* temp = head;
    ListNode* slow = temp;
    ListNode* fast = temp;

    if(temp == NULL) return temp;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
```

### Complexity
- Time: O(n), where n is the number of nodes in the linked list. In the worst case, the `fast` pointer traverses the entire list.
- Space: O(1), since only a constant amount of space is used to store the pointers.

## 🕵️‍♂️ Follow-up Questions (Optional)
Some common follow-up questions for this pattern include:
- What if the linked list is very large and the cycle is very long? The answer is that the algorithm will still work, and its time complexity remains O(n), where n is the total number of nodes.
- Can you find the cycle in a linked list using only one pointer? The answer is yes, by using a hash set to store the visited nodes, but this would increase the space complexity to O(n).