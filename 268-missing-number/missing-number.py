class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        i = 0
        n = len(nums)

        while i < n:
            if nums[i] == i or nums[i] >= n:
                i += 1
            else:
                temp = nums[i]
                nums[i] = nums[temp]
                nums[temp] = temp

        for j in range(n):
            if nums[j] != j:
                return j

        return n
