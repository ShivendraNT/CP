class Solution(object):
    def insert(self, intervals, newInterval):
        newinterval=[]
        temp=newInterval
        start=newInterval[0]
        end=newInterval[1]
        for i in range(len(intervals)):
            if intervals[i][1]<start or intervals[i][0]>end:
                newinterval.append(intervals[i])
            elif intervals[i][0]>=start and intervals[i][1]<=end:
                continue
            elif intervals[i][0]<start and intervals[i][1]>end:
                return intervals
            elif intervals[i][0]>=start and intervals[i][1]>=end:
                temp[1]=intervals[i][1]
            elif intervals[i][0]<=start:
                temp[0]=intervals[i][0]
                temp[1]=end
        newinterval.append(temp)
        newinterval=sorted(newinterval)
        return newinterval
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        
