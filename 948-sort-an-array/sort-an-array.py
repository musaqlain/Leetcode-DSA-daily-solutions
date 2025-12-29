class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        count = defaultdict(int)
        min_val, max_val = min(nums), max(nums)
        for val in nums:
            count[val] += 1

        index = 0
        for val in range(min_val, max_val+1):
            while count[val] > 0:
                nums[index] = val
                count[val] -= 1
                index += 1
        return nums