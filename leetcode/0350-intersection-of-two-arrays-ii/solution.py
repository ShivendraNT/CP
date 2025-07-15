class Solution(object):
    def intersect(self, nums1, nums2):
        d={}
        nums=[]
        for i in nums1:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        for j in nums2:
            if j in d and d[j]!=0:
                d[j]-=1
                nums.append(j)
        return nums
            
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
