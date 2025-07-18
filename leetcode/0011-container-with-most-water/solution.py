class Solution(object):
    def maxArea(self, height):
        area=0
        left=0
        right=len(height)-1
        while left<right:
            ar=min(height[left],height[right])*(right-left)
            if ar>area:
                area=ar
            if height[left]<height[right]:
                left+=1
            elif height[right]<=height[left]:
                right-=1
        return area
        """
        :type height: List[int]
        :rtype: int
        """
        
