class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        dic = {}
        lent = range(len(nums)+1)
        print(lent)
        for i in nums:
            if i not in dic:
                dic[i] = 1
        for i in lent:
            print(i)
            if i not in dic:
                return i