1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int n = nums.size(); int dup;
5
6        int slow = 0;
7        int fast = 0;
8
9        while(fast < n){
10            slow = nums[slow];
11            fast = nums[fast];
12            fast = nums[fast];
13
14            if(slow == fast){
15                slow = 0;
16                while(slow != fast){
17                    slow = nums[slow];
18                    fast = nums[fast];
19                }
20                return slow;
21            }
22        }
23        return -1;
24    }
25};