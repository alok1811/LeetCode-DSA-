<h2><a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii">154. Find Minimum in Rotated Sorted Array II</a></h2>

<p>Suppose an array of length <code>n</code> sorted in ascending order is <strong>rotated</strong> between <code>1</code> and <code>n</code> times. For example, the array <code>nums = [0,1,4,4,5,6,7]</code> might become:</p>

<ul>
	<li><code>[4,5,6,7,0,1,4]</code> if it was rotated <code>4</code> times.</li>
	<li><code>[0,1,4,4,5,6,7]</code> if it was rotated <code>7</code> times.</li>
</ul>

<p>Notice that <strong>rotating</strong> an array <code>[a[0], a[1], a[2], ..., a[n-1]]</code> 1 time results in the array <code>[a[n-1], a[0], a[1], a[2], ..., a[n-2]]</code>.</p>

<p>Given the sorted rotated array <code>nums</code> that may contain <strong>duplicates</strong>, return <em>the minimum element of this array</em>.</p>

<p>You must decrease the overall operation steps as much as possible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,5]
<strong>Output:</strong> 1
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,2,0,1]
<strong>Output:</strong> 0
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>-5000 &lt;= nums[i] &lt;= 5000</code></li>
	<li><code>nums</code> is sorted and rotated between <code>1</code> and <code>n</code> times.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> This problem is similar to&nbsp;<a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/" target="_blank">Find Minimum in Rotated Sorted Array</a>, but&nbsp;<code>nums</code> may contain <strong>duplicates</strong>. Would this affect the runtime complexity? How and why?</p>

<p>&nbsp;</p>


---

# 🛍️ Find-Minimum-in-Rotated-Sorted-Array-II | Explained

## Approach 1 (Brute Force)
### Intuition
The core idea behind this approach is to iterate through the entire array and keep track of the smallest element encountered. This approach works because it exhaustively checks every element in the array, ensuring that the minimum value is found. The intuition is similar to searching for a lost item in a messy room - you need to look through every possible location to guarantee finding what you're looking for.

### Approach
The step-by-step breakdown of this approach is straightforward:
1. Initialize a variable to store the minimum value found so far.
2. Iterate through the array, comparing each element to the current minimum.
3. If an element is smaller than the current minimum, update the minimum variable.
4. After iterating through the entire array, return the minimum value found.

### Detailed Code Analysis
Let's dive into the code block and break it down line by line:
- `int n = nums.size();`: This line retrieves the number of elements in the input array `nums`.
- `int minEl = INT_MAX;`: This line initializes a variable `minEl` to store the minimum value found so far. It's initialized to `INT_MAX`, which is the largest possible integer value, to ensure that any actual value in the array will be smaller.
- `for(int i = 0; i < n; i++)`: This loop iterates through each element in the array.
- `minEl = min(minEl, nums[i]);`: Inside the loop, this line compares the current minimum `minEl` with the current element `nums[i]`. If `nums[i]` is smaller, it updates `minEl` with this new minimum value.
- `return minEl;`: After the loop finishes, this line returns the minimum value found.

### Code
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minEl = INT_MAX;
        for(int i = 0; i < n; i++){
            minEl = min(minEl, nums[i]);
        }
        return minEl;
    }
};
```

### Complexity
- Time: The time complexity of this approach is O(n), where n is the number of elements in the input array. This is because the algorithm iterates through the array once, checking each element exactly once.
- Space: The space complexity is O(1), which means the space used does not grow with the size of the input array. This is because the algorithm only uses a constant amount of space to store the minimum value and the loop counter.

## 🕵️‍♂️ Follow-up Questions (Optional)
Some common follow-up questions for this pattern could be:
- What if the input array is empty? The current implementation would return `INT_MAX`, but a more appropriate solution might be to throw an exception or return a special value indicating an empty input.
- How would you optimize this solution for very large input arrays? One potential optimization could be to use a parallelized approach, dividing the array into smaller chunks and processing them concurrently to find the minimum value. However, for the "Find-Minimum-in-Rotated-Sorted-Array-II" problem specifically, a more efficient algorithm exists that takes advantage of the array's structure.