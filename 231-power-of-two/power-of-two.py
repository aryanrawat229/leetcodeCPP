class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False

        count = 0

        while n != 0:
            r = n % 2
            n = n // 2
            if r == 1:
                count += 1

        if count == 1:
            return True
        else:
            return False
