<h2><a href="https://leetcode.com/problems/reorder-list">143. Reorder List</a></h2>

<p>You are given the head of a singly linked-list. The list can be represented as:</p>

<pre>L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

<p><em>Reorder the list to be on the following form:</em></p>

<pre>L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …
</pre>

<p>You may not modify the values in the list's nodes. Only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg" style="width: 422px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [1,4,2,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [1,5,2,4,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>


---

# 🛍️ Reorder-List | Explained

## Approach 1 (Optimized)
### Intuition
The core idea behind this approach is to reorder the linked list in a way that alternates between nodes from the first half and the reversed second half of the list. This resembles a real-world analogy of shuffling two decks of cards together, where each deck is ordered and you want to interleave them. The approach works by first finding the middle of the list, then reversing the second half, and finally merging the two halves together in an alternating manner.

### Approach
The algorithmic steps can be broken down as follows:
1. Find the middle of the linked list using the slow and fast pointer technique.
2. Reverse the second half of the linked list.
3. Merge the first half and the reversed second half together in an alternating manner.

### Detailed Code Analysis
The provided code starts by defining a helper function `reverse(ListNode* head)` to reverse a linked list. This function works by initializing three pointers: `temp` to the current node, `prev` to the previous node (initially `NULL`), and iterating through the list until `temp` is `NULL`. In each iteration, it does the following:
- Stores the next node in `front` (`front = temp->next;`)
- Reverses the `next` pointer of the current node (`temp->next = prev;`)
- Moves both `prev` and `temp` one step forward (`prev = temp;` and `temp = front;`)
- Once the loop ends, `prev` points to the new head of the reversed list, which is returned.

The main function `reorderList(ListNode* head)` starts by initializing two pointers, `slow` and `fast`, to the head of the list. It uses these pointers to find the middle of the list. The `fast` pointer moves twice as fast as the `slow` pointer, so when `fast` reaches the end of the list, `slow` will be at the middle. The code then reverses the second half of the list using the `reverse` function and assigns it to `newHead`.

After reversing the second half, the code sets `slow->next` to `NULL` to effectively split the list into two halves. It then initializes two pointers, `first` and `second`, to the head of the first half and the head of the reversed second half, respectively.

The code then enters a loop that continues until the end of the second half is reached (`while(second != NULL)`). Inside the loop, it does the following:
- Stores the next nodes in both halves (`firstNext = first->next;` and `secondNext = second->next;`)
- Merges the two halves together by setting `first->next` to `second` and `second->next` to `firstNext`
- Moves both `first` and `second` one step forward (`first = firstNext;` and `second = secondNext;`)

### Code
```cpp
ListNode* reverse(ListNode* head){
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp != NULL){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = reverse(slow->next);
    slow->next = NULL;
    ListNode* first = head;
    ListNode* second = newHead;

    while(second != NULL){
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }
    return;
}
```

### Complexity
- Time: The time complexity of this approach is O(n), where n is the number of nodes in the linked list. This is because the code performs a constant amount of work for each node in the list.
- Space: The space complexity is O(1), as the code only uses a constant amount of space to store the pointers and variables, regardless of the size of the input list.

## 🕵️‍♂️ Follow-up Questions (Optional)
Some potential follow-up questions and brief answers:
1. **What if the input list is already ordered or has only a few unique elements?** The algorithm still works as intended, but its benefits may be less pronounced in terms of reordering efficiency.
2. **How would you modify the algorithm to handle a doubly linked list?** The basic idea remains the same, but you would need to update both the `next` and `prev` pointers when reversing and merging the lists.