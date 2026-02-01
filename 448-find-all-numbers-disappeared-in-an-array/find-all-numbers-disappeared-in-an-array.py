class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        temp = [0] * (n + 1)

        for num in nums:
            temp[num] += 1

        result = []
        for i in range(1, n + 1):
            if temp[i] == 0:
                result.append(i)

        return result
