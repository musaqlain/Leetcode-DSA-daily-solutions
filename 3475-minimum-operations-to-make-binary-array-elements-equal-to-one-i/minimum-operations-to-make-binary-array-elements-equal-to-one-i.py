class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # num of operations
        operations = 0

        for i in range(len(nums) - 2):
            if nums[i] == 0:
                operations += 1
                # logic machine
                nums[i] = 1 - nums[i]
                nums[i + 1] = 1 - nums[i + 1]
                nums[i + 2] = 1 - nums[i + 2]
        
        if nums[len(nums) - 2] == 0 or nums[len(nums) - 1] == 0:
            return -1

        return operations


            
            # ignore