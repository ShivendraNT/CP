class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()
        n = len(nums)
        res = {}

        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, n - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                diff=target-total
                if diff<0:
                    diff=diff*-1
                res[diff]=total
                if total == target:
                    left+=1
                    right-=1
                elif total < target:
                    left += 1
                else:
                    right -= 1
        return res[min(res.keys())]
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
