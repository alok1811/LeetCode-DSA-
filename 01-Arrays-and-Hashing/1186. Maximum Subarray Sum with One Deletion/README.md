<h2><a href="https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion">1186. Maximum Subarray Sum with One Deletion</a></h2>

<p>Given an array of integers, return the maximum sum for a <strong>non-empty</strong>&nbsp;subarray (contiguous elements) with at most one element deletion.&nbsp;In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the&nbsp;sum of the remaining elements is maximum possible.</p>

<p>Note that the subarray needs to be <strong>non-empty</strong> after deleting one element.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,0,3]
<strong>Output:</strong> 4
<strong>Explanation: </strong>Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,-2,3]
<strong>Output:</strong> 3
<strong>Explanation: </strong>We just choose [3] and it's the maximum sum.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [-1,-1,-1,-1]
<strong>Output:</strong> -1
<strong>Explanation:</strong>&nbsp;The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>


---

# 🛍️ Maximum-Subarray-Sum-with-One-Deletion | Explained

## Approach 1 (Optimized)
### Intuition
Imagine you are a portfolio manager trying to maximize the return on investment of a series of stock transactions. Each stock transaction can either be added to your existing portfolio or you can choose to delete one previous transaction to get a better return. This problem can be thought of as finding the maximum subarray sum with the option to delete at most one element. The intuition behind this approach is to use dynamic programming to track the maximum sum we can get with and without deleting an element.

### Approach
The algorithm works by maintaining two variables: `noDelete` and `oneDelete`, which represent the maximum sum we can get without deleting any element and with deleting one element, respectively. We iterate through the array, and for each element, we update these variables to reflect the maximum sum we can get by including or excluding the current element.

### Detailed Code Analysis
Let's dive into the code:
```cpp
int n = arr.size();
int noDelete = arr[0];
int oneDelete = arr[0];
int ans = arr[0];
```
Here, we initialize the variables `noDelete`, `oneDelete`, and `ans` with the first element of the array. `noDelete` and `oneDelete` will store the maximum sum we can get without deleting any element and with deleting one element, respectively, up to the current index. `ans` will store the overall maximum sum.

```cpp
for(int i = 1; i < n; i++){
    int prevNoDelete = noDelete;
    int prevOneDelete = oneDelete;

    noDelete = max(noDelete + arr[i], arr[i]);
    oneDelete = max(prevNoDelete, oneDelete + arr[i]);
    ans = max(ans, max(oneDelete, noDelete));
}
```
Inside the loop, we first store the previous values of `noDelete` and `oneDelete`. Then, we update `noDelete` to be the maximum of the current sum plus the current element, and the current element itself. This is because we can either include the current element in the sum or start a new sum from the current element. We update `oneDelete` to be the maximum of the previous sum without deletion (`prevNoDelete`) and the current sum with deletion plus the current element. Finally, we update `ans` to be the maximum of the current sum and the overall maximum sum.

### Code
```cpp
int maximumSum(vector<int>& arr) {
    int n = arr.size();

    int noDelete = arr[0];
    int oneDelete = arr[0];

    int ans = arr[0];

    for(int i = 1; i < n; i++){
        int prevNoDelete = noDelete;
        int prevOneDelete = oneDelete;

        noDelete = max(noDelete + arr[i], arr[i]);

        oneDelete = max(prevNoDelete, oneDelete + arr[i]);

        ans = max(ans, max(oneDelete, noDelete));
    }
    return ans;
}
```
### Complexity
- Time: The time complexity of this approach is O(n), where n is the number of elements in the array, because we are making a single pass through the array.
- Space: The space complexity of this approach is O(1), because we are using a constant amount of space to store the variables `noDelete`, `oneDelete`, and `ans`.

## 🕵️‍♂️ Follow-up Questions (Optional)
1. How would you handle the case where the input array is empty? 
   The code would need to be modified to handle this edge case, for example, by returning 0 or throwing an exception.
2. Can you modify the algorithm to find the maximum subarray sum with at most k deletions? 
   This would require modifying the algorithm to use a more complex data structure, such as a queue or a stack, to keep track of the maximum sum with up to k deletions.