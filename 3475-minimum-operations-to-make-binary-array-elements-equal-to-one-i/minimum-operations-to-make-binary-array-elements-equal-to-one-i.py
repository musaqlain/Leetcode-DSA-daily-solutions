class Solution:
    def minOperations(self, nums: List[int]) -> int:
        operations = 0
        n = len(nums)

        for i in range(n - 2):

            if nums[i] == 0:
                operations += 1
                # run this logic
                nums[i] = 1 - nums[i]
                nums[i + 1] = 1 - nums[i + 1]
                nums[i + 2] = 1 - nums[i + 2]
        
        if nums[n - 2] == 0 or nums[n - 1] == 0:
            return -1
        return operations