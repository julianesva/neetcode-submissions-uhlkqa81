class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if(len(numbers) == 2):
            return [1,2]

        l = 0
        r = len(numbers) - 1
        while(l < r):
            add = numbers[l] + numbers[r]
            res = add - target

            if(res == 0):
                return [l+1, r+1]
            if(res > 0):
                r-=1
            else:
                l+=1

        return []
