class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        count1 = {}

        for let in s1: 
            count1[let] = 1 + count1.get(let, 0)

        need = len(count1)

        for i in range(len(s2)):
            count2 = {}
            count = 0
            for j in range(i, len(s2)): 
                count2[s2[j]] = 1 + count2.get(s2[j], 0)
                if count1.get(s2[j], 0) < count2[s2[j]]: 
                    break
                elif count1.get(s2[j], 0) == count2[s2[j]]: 
                    count+= 1
                if count == need: 
                    return True                
        return False





