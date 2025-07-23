class Solution(object):
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        n = len(matrix[0])

        # Binary search over rows to find the correct row
        top = 0
        bottom = m - 1
        target_row = -1

        while top <= bottom:
            mid = (top + bottom) // 2
            row = matrix[mid]
            if row[0] <= target <= row[-1]:
                target_row = mid
                break
            elif target < row[0]:
                bottom = mid - 1
            else:
                top = mid + 1

        if target_row == -1:
            return False

        # Binary search within the identified row
        row = matrix[target_row]
        left = 0
        right = n - 1

        while left <= right:
            mid = (left + right) // 2
            if row[mid] == target:
                return True
            elif row[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return False
