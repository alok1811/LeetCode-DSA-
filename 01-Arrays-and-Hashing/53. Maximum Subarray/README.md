<h2><a href="https://leetcode.com/problems/maximum-subarray">53. Maximum Subarray</a></h2>

<p>Given an integer array <code>nums</code>, find the <span data-keyword="subarray-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_1l_" data-state="closed" class="">subarray</button></span> with the largest sum, and return <em>its sum</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The subarray [4,-1,2,1] has the largest sum 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The subarray [1] has the largest sum 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,-1,7,8]
<strong>Output:</strong> 23
<strong>Explanation:</strong> The subarray [5,4,-1,7,8] has the largest sum 23.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.</p>


---

# 🛍️ Maximum-Subarray | Explained

## Approach 1: Kadane's Algorithm
### Intuition
Imagine you are on a financial investment journey, and each day, you either gain or lose money. Your goal is to find the best consecutive period (subarray) where your net gain is the highest. If you start with a negative gain, it's better to reset and start fresh, hoping to find a profitable period later. Similarly, if you're in a profitable period, you want to keep adding to it until you find a better start. This approach works because it dynamically decides whether to continue with the current subarray or start fresh at each step, ensuring the maximum sum is found.

### Approach
Kadane's Algorithm is an efficient solution for finding the maximum subarray sum. It works by maintaining two variables: one for the best sum found so far and another for the best sum including the current element. For each element, it checks whether including the current element in the current sum would be beneficial or if it's better to start fresh with the current element. This decision is made by comparing the sum of the current element with the previous best sum plus the current element.

### Detailed Code Analysis
Let's break down the provided code:
- `int bestAns = nums[0];` and `int ans = nums[0];`: These lines initialize two variables, `bestAns` and `ans`, with the first element of the array. `bestAns` keeps track of the maximum subarray sum ending at the current position, while `ans` stores the maximum subarray sum seen so far. 
- The loop `for(int i = 1; i < n; i++)` iterates over the array starting from the second element (index 1). 
- Inside the loop:
  - `int value1 = bestAns + nums[i];` calculates the potential new sum if we extend the current subarray by adding the current element.
  - `int value2 = nums[i];` considers the current element as the start of a new subarray.
  - `bestAns = max(value1, value2);` decides whether to extend the current subarray or start a new one, choosing the maximum between the two values. This step is crucial as it ensures we're always considering the best possible sum up to the current point.
  - `ans = max(bestAns, ans);` updates the overall maximum subarray sum found so far if the current `bestAns` is greater.
- The loop continues this process for each element, effectively sliding through the array and keeping track of the best sum seen.

### Code
```java
int bestAns = nums[0];
int ans = nums[0];
for(int i = 1; i < n; i++){
    int value1 = bestAns + nums[i];
    int value2 = nums[i];
    bestAns = max(value1, value2);
    ans = max(bestAns, ans);
}
return ans;
```

### Complexity
- Time: The algorithm iterates over the array once, resulting in a time complexity of O(n), where n is the number of elements in the array. The operations inside the loop (addition and comparison) take constant time, thus not affecting the overall time complexity.
- Space: The algorithm uses a constant amount of space to store the variables `bestAns`, `ans`, `value1`, `value2`, and the loop counter `i`, making the space complexity O(1). This is efficient as it doesn't use any data structures that scale with the input size.

## 🕵️‍♂️ Follow-up Questions (Optional)
1. **What if all numbers in the array are negative?** In this case, the maximum subarray sum will be the maximum single element in the array, as including more negative numbers would decrease the sum. Kadane's algorithm correctly handles this by always considering the current element as a potential start of a new subarray, ensuring that the single maximum negative number is returned as the "maximum" subarray sum.
2. **How would you modify the algorithm to find the actual subarray (not just its sum)?** To find the actual subarray, you would need to keep track of the start and end indices of the subarray with the maximum sum. You could introduce two more variables to store these indices and update them whenever a new maximum sum is found. This modification would allow you to return the subarray itself, not just its sum.