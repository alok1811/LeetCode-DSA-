1class Solution {
2public:
3    int maxSubarraySumCircular(vector<int>& nums) {
4        int n = nums.size();
5
6        int currentMin = 0;
7        int currentMax = 0;
8
9        int minSum = INT_MAX;
10        int maxSum = INT_MIN;
11
12        int total = 0;
13
14        for(int i = 0; i < n; i++){
15            currentMin = min(currentMin + nums[i], nums[i]);
16            minSum = min(currentMin, minSum);
17
18            currentMax = max(currentMax + nums[i], nums[i]);
19            maxSum = max(maxSum, currentMax);
20
21            total = total + nums[i];
22        }
23
24        if (maxSum < 0){
25            return maxSum;
26        }
27
28        int circular = total - minSum;
29
30        return max(maxSum, circular);
31    }
32};