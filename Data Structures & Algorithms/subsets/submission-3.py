class Solution:

    def allsubsets(self, nums: List[int], subsets: List[List[int]], curr: int, curr_set: List[int]) -> None:
        if curr >= len(nums): 
            return

        for curr in range(curr, len(nums)): 
            curr_set.append(nums[curr])
            print(curr_set)
            subsets.append(curr_set.copy())
            self.allsubsets(nums, subsets, curr+1, curr_set)
            curr_set.pop()




    def subsets(self, nums: List[int]) -> List[List[int]]:

        subsets = list()
        subsets.append([])
        curr_set = []
        response = []

        self.allsubsets(nums, subsets, 0, curr_set)

        return subsets
        