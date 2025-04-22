class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        hastb = {}

        # 2 pass hashtable solution
        for i in range(n):
            hastb[nums[i]] = i

        for i in range(n):
            desired = target - nums[i]
            if desired in hastb and i != hastb[desired]:
                return [hastb[desired], i]
            
        return []
        