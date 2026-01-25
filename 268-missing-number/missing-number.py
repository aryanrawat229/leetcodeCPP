class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        total = 0

        for i in range(len(nums)):
            total ^= nums[i]

        for i in range(len(nums) + 1):
            total ^= i

        return total
