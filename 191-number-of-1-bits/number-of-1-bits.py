class Solution:
    def hammingWeight(self, n: int) -> int:
        count=0

        while n!=0:
            r=n%2
            if r==1:
                count+=1
            n=n//2
        
        return count