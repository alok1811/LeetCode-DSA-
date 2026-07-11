1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int n = nums.size(); int dup;
5
6        unordered_map<int, int> mpp;
7
8        for(int i = 0; i < n; i++){
9            mpp[nums[i]]++;
10        }
11
12        for(int i = 0; i < n; i++){
13            if(mpp[nums[i]] > 1){
14                dup = nums[i];
15            }
16        }
17        return dup;
18    }
19};