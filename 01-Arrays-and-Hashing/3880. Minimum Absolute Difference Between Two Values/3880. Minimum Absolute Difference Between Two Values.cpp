1class Solution {
2public:
3    int minAbsoluteDifference(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> nums1;
7        vector<int> nums2;
8
9        for(int i = 0; i < n; i++){
10            if(nums[i] == 1){
11                nums1.push_back(i);
12            }
13            else if(nums[i] == 2){
14                nums2.push_back(i);
15            }
16            else{
17                continue;
18            }
19        }
20        int minDiff = INT_MAX;
21        int size1 = nums1.size();
22        int size2 = nums2.size();
23
24        if(size1 == 0){
25            return -1;
26        }
27        if(size2 == 0){
28            return -1;
29        }
30
31        for(int i = 0; i < size1; i++){
32            for(int j = 0; j < size2; j++){
33                int diff = abs(nums1[i] - nums2[j]);
34                minDiff = min(diff, minDiff);
35            }
36        }
37        return minDiff;
38    }
39};