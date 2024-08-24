class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n= len(nums)
        mem = {}

        def dfs(i, current_sum):
            # base
            if i >= n:
                if current_sum == target:
                    return 1
                else:
                    return 0
            
            if (i, current_sum) in mem:
                return mem[(i, current_sum)]

            # main
            # +
            add = dfs(i+1, current_sum + nums[i])

            #-
            substract = dfs(i+1, current_sum - nums[i])

            mem[(i, current_sum)] = add + substract
            return mem[(i, current_sum)] 

        return dfs(0, 0)
        