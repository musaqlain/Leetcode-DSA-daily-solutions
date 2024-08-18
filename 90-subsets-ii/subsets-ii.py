class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []

        nums.sort()

        def backtrack(i, curr):
            # base
            if i>= len(nums):
                ans.append(curr[:])
                return
            
            # main
            # taken
            curr.append(nums[i])
            backtrack(i+1, curr)

            # not taken
            curr.remove(nums[i])
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i+=1
            backtrack(i+1, curr)

        backtrack(0, [])

        return ans