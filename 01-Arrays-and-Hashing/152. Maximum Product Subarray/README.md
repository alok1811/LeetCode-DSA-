<h2><a href="https://leetcode.com/problems/maximum-product-subarray">152. Maximum Product Subarray</a></h2>

<p>Given an integer array <code>nums</code>, find a <span data-keyword="subarray-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_1l_" data-state="closed" class="">subarray</button></span> that has the largest product, and return <em>the product</em>.</p>

<p>The test cases are generated so that the answer will fit in a <strong>32-bit</strong> integer.</p>

<p><strong>Note</strong> that the product of an array with a single element is the value of that element.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,-2,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> [2,3] has the largest product 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-2,0,-1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The result cannot be 2, because [-2,-1] is not a subarray.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>The product of any subarray of <code>nums</code> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</li>
</ul>


---

# 🛍️ Maximum-Product-Subarray | Explained

## Approach 1 (Partial and Incomplete)
### Intuition
This approach seems to be an attempt to solve the Maximum-Product-Subarray problem using dynamic programming. The core idea is to maintain two variables, `minEnd` and `maxEnd`, to keep track of the minimum and maximum product of the subarray ending at each position.

### Approach
The algorithmic breakdown is as follows:
1. Initialize `ans` with the first element of the array.
2. Iterate through the array from the second element to the end.
3. For each element, calculate three values: `value0` (product of `minEnd` and the current element), `value1` (product of `maxEnd` and the current element), and `value2` (the current element itself).
4. Update `minEnd` and `maxEnd` by taking the minimum and maximum of the three calculated values.
5. Update `ans` with the maximum of `ans`, `minEnd`, and `maxEnd`.

### Detailed Code Analysis
Let's break down the code step-by-step:
- `long ans = nums[0];`: Initializes `ans` with the first element of the array.
- `for (int i = 1; i < n; i++)`: Iterates through the array from the second element to the end.
- `long value0 = minEnd * nums[i];`, `long value1 = maxEnd * nums[i];`, and `long value2 = nums[i];`: Calculate the three values for the current element.
- `minEnd = min(value0, min(value1, value2))`: Updates `minEnd` with the minimum of the three calculated values.
- `maxEnd = max(value0, max(value1, value2))`: Updates `maxEnd` with the maximum of the three calculated values.
- `ans = max(ans, max(minEnd, maxEnd))`: Updates `ans` with the maximum of `ans`, `minEnd`, and `maxEnd`.

However, it's essential to note that the initialization of `minEnd` and `maxEnd` is incorrect. The correct initialization should be `minEnd = maxEnd = nums[0];` before the loop. Additionally, the given code seems to be incomplete, and the variables `n`, `maxEnd`, and `minEnd` are not properly declared.

### Code
```cpp
int n = nums.size();
long ans = nums[0];
long maxEnd = nums[0];
long minEnd = nums[0];

for (int i = 1; i < n; i++) {
    long value0 = minEnd * nums[i];
    long value1 = maxEnd * nums[i];
    long value2 = nums[i];

    minEnd = min(value0, min(value1, value2));
    maxEnd = max(value0, max(value1, value2));

    ans = max(ans, max(minEnd, maxEnd));
}
```

### Complexity
- Time: O(n), where n is the size of the input array, because we're doing a single pass through the array.
- Space: O(1), because we're using a constant amount of space to store the variables `ans`, `maxEnd`, `minEnd`, `value0`, `value1`, and `value2`.

## 🕵️‍♂️ Follow-up Questions (Optional)
Some common follow-up questions for this problem are:
1. How would you handle the case when the input array is empty?
   - You can add a simple check at the beginning of the function to return 0 or a specific value when the input array is empty.
2. What if the input array contains only one element?
   - In this case, the function should return the only element in the array, because the maximum product subarray is the array itself.