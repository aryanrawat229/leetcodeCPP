class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        i = 0
        n = len(nums)

        while i < n:
            correct_index = nums[i] - 1

            if nums[i] != nums[correct_index]:
                nums[i], nums[correct_index] = nums[correct_index], nums[i]
            else:
                # If index is not correct and values are same → duplicate found
                if i != correct_index:
                    return nums[i]
                i += 1
