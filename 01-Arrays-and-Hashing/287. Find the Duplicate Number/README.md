<h2><a href="https://leetcode.com/problems/find-the-duplicate-number">287. Find the Duplicate Number</a></h2>

<p>Given an array of integers <code>nums</code> containing&nbsp;<code>n + 1</code> integers where each integer is in the range <code>[1, n]</code> inclusive.</p>

<p>There is only <strong>one repeated number</strong> in <code>nums</code>, return <em>this&nbsp;repeated&nbsp;number</em>.</p>

<p>You must solve the problem <strong>without</strong> modifying the array <code>nums</code>&nbsp;and using only constant extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,4,2,2]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,3,4,2]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3,3,3,3]
<strong>Output:</strong> 3</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n + 1</code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li>All the integers in <code>nums</code> appear only <strong>once</strong> except for <strong>precisely one integer</strong> which appears <strong>two or more</strong> times.</li>
</ul>

<p>&nbsp;</p>
<p><b>Follow up:</b></p>

<ul>
	<li>How can we prove that at least one duplicate number must exist in <code>nums</code>?</li>
	<li>Can you solve the problem in linear runtime complexity?</li>
</ul>


---

# 🛍️ Find-the-Duplicate-Number | Explained

## Approach 1: Floyd's Tortoise and Hare Algorithm
### Intuition
The idea behind this approach is to treat the given array as a linked list, where each element is a node and its value is the next node's index. The presence of a duplicate in the array implies that there is a cycle in this linked list. We can use Floyd's Tortoise and Hare algorithm, also known as the "cycle detection" algorithm, to find the start of the cycle, which corresponds to the duplicate number. This algorithm is commonly used to detect cycles in linked lists, but it can also be applied to this problem.

### Approach
The algorithm works by using two pointers, a slow pointer and a fast pointer, to traverse the "linked list". The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. If there is a cycle, the fast pointer will eventually catch up to the slow pointer. Once this happens, we reset the slow pointer to the start and move both pointers one step at a time. The point where they meet again is the start of the cycle, which corresponds to the duplicate number.

### Detailed Code Analysis
Let's take a closer look at the code:
```cpp
int n = nums.size(); int dup;
int slow = 0;
int fast = 0;
```
Here, we initialize the `slow` and `fast` pointers to 0, which corresponds to the start of the "linked list". We also store the size of the input array `nums` in the variable `n`.
```cpp
while(fast < n){
    slow = nums[slow];
    fast = nums[fast];
    fast = nums[fast];
```
 Inside the while loop, we move the `slow` pointer one step at a time by updating its value to the value at the current index. We move the `fast` pointer two steps at a time by updating its value to the value at the index stored in the `fast` pointer. This is done twice in a row to move the `fast` pointer two steps ahead.
```cpp
if(slow == fast){
    slow = 0;
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
```
If the `slow` and `fast` pointers meet, we reset the `slow` pointer to the start and move both pointers one step at a time. When they meet again, we return the value of the `slow` pointer, which corresponds to the duplicate number.

### Code
```cpp
int findDuplicate(vector<int>& nums) {
    int n = nums.size(); 
    int slow = 0;
    int fast = 0;

    while(fast < n){
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];

        if(slow == fast){
            slow = 0;
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
    }
    return -1;
}
```
### Complexity
- Time: The time complexity of this algorithm is O(n), where n is the number of elements in the input array. This is because we potentially traverse the array twice: once to detect the cycle and once to find the start of the cycle.
- Space: The space complexity of this algorithm is O(1), which means the space required does not grow with the size of the input array. We only use a constant amount of space to store the `slow` and `fast` pointers.

## 🕵️‍♂️ Follow-up Questions (Optional)
Some common follow-up questions for this problem might include:
- Can you explain why this algorithm works?
- What are the trade-offs between this algorithm and other approaches, such as using a hashmap to store the elements we've seen so far? 
The brief answers would be:
- This algorithm works by detecting the cycle in the "linked list" created by the input array and finding the start of the cycle, which corresponds to the duplicate number.
- The trade-offs between this algorithm and other approaches include space complexity (this algorithm uses O(1) space, while a hashmap-based approach would use O(n) space) and simplicity (this algorithm is more complex and harder to understand than a simple hashmap-based approach).