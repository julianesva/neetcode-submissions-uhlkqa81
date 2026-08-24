class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        hash_m = {}

        for i, num in enumerate(nums): 
            if((target - num) in hash_m): 
                return [hash_m[target - num], i]
            else: 
                hash_m[num] = i

        