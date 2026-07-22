1class Solution {
2public:
3    int maxAbsoluteSum(vector<int>& nums) {
4        int n = nums.size();
5
6        int maxEnd = nums[0];
7        int minEnd = nums[0];
8        int maxSum = nums[0];
9        int minSum = nums[0];
10        for(int i = 1; i < n; i++){
11            maxEnd = max(nums[i], maxEnd + nums[i]);
12            maxSum = max(maxEnd, maxSum);
13
14            minEnd = min(nums[i], nums[i] + minEnd);
15            minSum = min(minEnd, minSum);
16        }
17        return max(abs(minSum), abs(maxSum));
18    }
19};