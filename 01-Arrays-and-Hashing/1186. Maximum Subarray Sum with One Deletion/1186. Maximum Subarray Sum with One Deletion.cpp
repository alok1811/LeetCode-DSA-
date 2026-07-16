1class Solution {
2public:
3    int maximumSum(vector<int>& arr) {
4        int n = arr.size();
5
6        int noDelete = arr[0];
7        int oneDelete = arr[0];
8
9        int ans = arr[0];
10
11        for(int i = 1; i < n; i++){
12            int prevNoDelete = noDelete;
13            int prevOneDelete = oneDelete;
14
15            noDelete = max(noDelete + arr[i], arr[i]);
16
17            oneDelete = max(prevNoDelete, oneDelete + arr[i]);
18
19            ans = max(ans, max(oneDelete, noDelete));
20        }
21        return ans;
22    }
23};