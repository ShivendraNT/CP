class Solution(object):
    def merge(self, nums1, m, nums2, n):
        num=nums1
        if m==0:
            for i in range(0,n):
                num[i] = nums2[i]
        elif n==0:
            return nums1
        else:
            for i in range(m,m+n):
                num[i]=nums2[i-m]
        num=sorted(num)
        for i in range(len(nums1)):
            nums1[i]=num[i]
        return nums1
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        
