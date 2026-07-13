<h2><a href="https://leetcode.com/problems/palindrome-linked-list">234. Palindrome Linked List</a></h2>

<p>Given the <code>head</code> of a singly linked list, return <code>true</code><em> if it is a </em><span data-keyword="palindrome-sequence" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_1l_" data-state="closed" class=""><em>palindrome</em></button></span><em> or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;">
<pre><strong>Input:</strong> head = [1,2,2,1]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;">
<pre><strong>Input:</strong> head = [1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do it in <code>O(n)</code> time and <code>O(1)</code> space?

---

# 🛍️ Palindrome-Linked-List | Explained

## Approach 1 (Two-Pointer Technique with List Reversal)
### Intuition
Imagine being at a restaurant and you're trying to check if the food items on the menu are the same when read forward and backward, but the menu items are written on separate slips of paper, each linked to the next one. To efficiently check this, you could start from the beginning of the menu and the end of the menu (after reversing the second half), and then move towards the center, comparing the items at each step. This approach works by dividing the linked list into two halves, reversing the second half, and then comparing the nodes from the start of the first half and the start of the reversed second half.

### Approach
1. Find the middle of the linked list using the two-pointer technique (slow and fast pointers).
2. Reverse the second half of the linked list.
3. Compare the nodes from the start of the first half and the start of the reversed second half.
4. If all pairs of nodes have the same value, the linked list is a palindrome.

### Detailed Code Analysis
The code starts by defining a helper function `reverse` to reverse a linked list. This function takes the head of the list to be reversed and returns the new head after reversal.

The `isPalindrome` function checks if the linked list is a palindrome. It first handles the base case where the list is empty or only contains one node. Then, it uses the two-pointer technique to find the middle of the linked list.

```cpp
ListNode* slow = head;
ListNode* fast = head;
```

The `fast` pointer moves twice as fast as the `slow` pointer, so when the `fast` pointer reaches the end of the list, the `slow` pointer is at the middle.

```cpp
while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
}
```

After finding the middle, the code reverses the second half of the linked list.

```cpp
ListNode* newhead = reverse(slow->next);
```

Then, it compares the nodes from the start of the first half and the start of the reversed second half.

```cpp
ListNode* first = head;
ListNode* second = newhead;
while(second != NULL){
    if(first->val != second->val){
        return false;
    }
    first = first->next;
    second = second->next;
}
```

If all pairs of nodes have the same value, the linked list is a palindrome, and the function returns `true`.

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

bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return true;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newhead = reverse(slow->next);
    ListNode* first = head;
    ListNode* second = newhead;
    while(second != NULL){
        if(first->val != second->val){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}
```

### Complexity
- Time: O(n), where n is the number of nodes in the linked list. The time complexity is linear because we are scanning the list twice: once to find the middle and reverse the second half, and once to compare the nodes.
- Space: O(1), which means the space required does not change with the size of the input linked list. This is because we are only using a constant amount of space to store the pointers and variables, regardless of the size of the input.

## 🕵️‍♂️ Follow-up Questions (Optional)
1. **How would you optimize the space complexity if the input linked list is very large?** 
   - In this case, the space complexity is already O(1), which is optimal. However, if we were using a recursive approach to reverse the linked list, we could optimize the space complexity by using an iterative approach instead, to avoid the recursive call stack.

2. **What if the linked list nodes contain more than just an integer value, but also additional data?**
   - In that case, we would need to modify the comparison in the `isPalindrome` function to check all the relevant data fields of the nodes, not just the `val` field. This would involve changing the `if (first->val != second->val)` line to compare all the relevant fields.