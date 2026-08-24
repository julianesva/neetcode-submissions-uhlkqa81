class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        hash_m = {}

        for i in range(len(nums)): 
            if((target - nums[i]) in hash_m): 
                return [hash_m[target - nums[i]], i]
            else: 
                hash_m[nums[i]] = i

        