class Solution:
    def rob(self, nums: List[int]) -> int:
        # hash vector array
        # STEP #1
        dp = [-1] * (len(nums) +1) # n + 1

        def dfs(i, nums):
            # base condition
            if i >= len(nums):
                return 0

            if len(nums) - 1 == i:
                return nums[i]

            # STEP #2
            if (dp[i] != -1):
                return dp[i]

            # Not Take
            left = dfs(i+1, nums)

            # Take
            right = nums[i] + dfs(i+2, nums)

            # return maximum
            # STEP #3
            dp[i] = max(left, right)
            return dp[i] 

        return dfs(0, nums)