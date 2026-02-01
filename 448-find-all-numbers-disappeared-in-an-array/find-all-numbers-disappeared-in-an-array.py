class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i = 0

        # Cyclic sort
        while i < n:
            correct_index = nums[i] - 1

            if nums[i] == nums[correct_index]:
                i += 1
            else:
                nums[i], nums[correct_index] = nums[correct_index], nums[i]

        # Find missing numbers
        ans = []
        for j in range(n):
            if nums[j] != j + 1:
                ans.append(j + 1)

        return ans