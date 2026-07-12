1class Solution(object):
2    def secondsBetweenTimes(self, startTime, endTime):
3        
4        :type startTime: str
5        :type endTime: str
6        :rtype: int
7        
8
9        def seconds(n):
10            h = int(n[0:2])
11            m = int(n[3:5])
12            s = int(n[6:8])
13
14            return h*3600+m*60+s
15        return seconds(endTime) - seconds(startTime)
16        