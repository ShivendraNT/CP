class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums1.extend(nums2)
        nums1.sort()
        n=len(nums1)
        if len(nums1)%2==0:
            mid=n//2
            return (nums1[mid-1]+nums1[mid])/2.0
        else:
            return float(nums1[n//2])
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
