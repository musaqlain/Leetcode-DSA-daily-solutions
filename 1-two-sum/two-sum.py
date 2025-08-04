class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtb = {}
        n = len(nums)

        for i in range(n):
            hashtb[nums[i]] = i
        
        for i in range(n):
            desired = target - nums[i]

            if desired in hashtb and i != hashtb[desired]:
                return [i, hashtb[desired]]
