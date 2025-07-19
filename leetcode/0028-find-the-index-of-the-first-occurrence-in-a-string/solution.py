class Solution(object):
    def strStr(self, haystack, needle):
        if needle in haystack:
            return haystack.index(needle)
        else:
            return -1
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        
