<h2><a href="https://leetcode.com/problems/happy-number">202. Happy Number</a></h2>

<p>Write an algorithm to determine if a number <code>n</code> is happy.</p>

<p>A <strong>happy number</strong> is a number defined by the following process:</p>

<ul>
	<li>Starting with any positive integer, replace the number by the sum of the squares of its digits.</li>
	<li>Repeat the process until the number equals 1 (where it will stay), or it <strong>loops endlessly in a cycle</strong> which does not include 1.</li>
	<li>Those numbers for which this process <strong>ends in 1</strong> are happy.</li>
</ul>

<p>Return <code>true</code> <em>if</em> <code>n</code> <em>is a happy number, and</em> <code>false</code> <em>if not</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 19
<strong>Output:</strong> true
<strong>Explanation:</strong>
1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


---

# 🛍️ Happy-Number | Explained

## Approach 1 (Floyd's Tortoise and Hare Cycle Detection)
### Intuition
Imagine you're trying to detect a cycle in a circular track. You can have two runners, one running at a slow pace (tortoise) and the other running at a fast pace (hare). If there is a cycle, the hare will eventually catch up to the tortoise. In the context of the Happy-Number problem, this approach works by treating the sequence of numbers as a circular track. If the sequence enters a cycle, the fast and slow runners will eventually meet, indicating that the number is not happy.

### Approach
The algorithmic approach involves using Floyd's Tortoise and Hare algorithm to detect a cycle in the sequence of numbers. The slow and fast runners are initialized to the input number `n`. In each iteration, the slow runner moves one step forward by calculating the next number in the sequence using the `func` function, while the fast runner moves two steps forward by applying the `func` function twice. If the fast and slow runners meet and the meeting point is not 1, the number is not happy.

### Detailed Code Analysis
The provided code is incomplete and seems to be a mix of different approaches. However, we can try to analyze the given code block.

- The line `int slow = n;` initializes the slow runner to the input number `n`.
- The line `int fast = n;` initializes the fast runner to the input number `n`.
- The `while` loop condition `fast != 1` indicates that the loop will continue until the fast runner reaches 1, which means the number is happy.
- Inside the loop, the lines `slow = func(slow);` and `fast = func(fast);` move the slow and fast runners one step forward.
- The line `fast = func(fast);` moves the fast runner another step forward, which is the second application of the `func` function for the fast runner.
- The `if` statement `if(slow == fast && slow != 1)` checks if the fast and slow runners have met and the meeting point is not 1. If this condition is true, the function returns `false`, indicating that the number is not happy.

However, the given code has some issues, such as:
- The `return sum;` statement is outside the function and seems to be a leftover from another approach.
- The `int sum = 0;` and `int d = n % 10;` lines are not used in this approach and seem to be part of another solution.
- The `while(n > 0)` loop is unfinished and not used in this approach.

### Code
The correct code for this approach would be:
```cpp
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = func(slow);
            fast = func(func(fast));
        } while (slow != fast);
        return slow == 1;
    }

    int func(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};
```

### Complexity
- Time: The time complexity of this approach is O(log n), where n is the input number. The number of iterations in the `while` loop is bounded by the number of digits in the input number.
- Space: The space complexity is O(1), as only a constant amount of space is used to store the slow and fast runners.

## 🕵️‍♂️ Follow-up Questions (Optional)
- Q: Can you modify the `func` function to calculate the sum of squares of digits without using a `while` loop?
A: Yes, you can use a recursive approach to calculate the sum of squares of digits.
- Q: How would you optimize the solution for large input numbers?
A: You can use a hash set to store the visited numbers to detect the cycle, which would reduce the time complexity to O(log n) and space complexity to O(log n).