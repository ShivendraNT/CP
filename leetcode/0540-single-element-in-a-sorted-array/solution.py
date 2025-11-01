class Solution(object):
    def singleNonDuplicate(self, nums):
        left=0
        n=len(nums)
        right=n
        while(left<=right):
            mid=left+(right-left)/2
            if ((mid==0 or nums[mid]!=nums[mid-1]) and (mid==n-1 or nums[mid]!=nums[mid+1])):
                return nums[mid]
            elif(nums[mid]==nums[mid-1]):
                if (mid%2==0):
                    right=mid-1
                else:
                    left=mid+1
            else:
                if (mid%2==0):
                    left=mid+1
                else:
                    right=mid-1
        return 0
        """
        :type nums: List[int]
        :rtype: int
        """
        
