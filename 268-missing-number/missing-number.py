class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor1 = 0
        xor2 = 0
        count = 0
        for num in nums:
            xor1 = xor1 ^ count
            count += 1
            xor2 = xor2 ^ num
        
        xor1 = xor1 ^ len(nums)

        return xor1 ^ xor2
        