class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total_sum=0
        for i in range(len(nums)):  
            total_sum+=nums[i]

        left_sum=0
        right_sum=total_sum
        for j in range(len(nums)):
            right_sum-= nums[j]

            if left_sum == right_sum:
                return j
            left_sum+=nums[j]

        return -1
