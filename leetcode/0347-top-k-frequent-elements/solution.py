class Solution(object):
    def topKFrequent(self, nums, k):
        wordcount = {}
        for i in nums:
            wordcount[i] = wordcount.get(i, 0) + 1

    # Sort the items by frequency in descending order
        sorted_items = sorted(wordcount.items(), key=lambda x: -x[1])

    # Take the top k keys
        return [key for key, value in sorted_items[:k]]


        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        
