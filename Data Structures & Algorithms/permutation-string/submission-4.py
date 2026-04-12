class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        count1 = defaultdict(int)

        for let in s1: 
            count1[let] += 1

        need = len(count1)

        for i in range(len(s2)):
            count2 = defaultdict(int)
            count = 0

            for j in range(i, len(s2)): 
                count2[s2[j]] += 1

                if count1[s2[j]] < count2[s2[j]]: 
                    break
                elif count1[s2[j]] == count2[s2[j]]: 
                    count += 1

                if count == need: 
                    return True                

        return False