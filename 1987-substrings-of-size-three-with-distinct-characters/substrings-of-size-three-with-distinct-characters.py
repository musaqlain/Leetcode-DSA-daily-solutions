class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        count = 0
        for i in range(len(s)-2):
            char1 = s[i]
            char2 = s[i+1]
            char3 = s[i+2]
            
            if char1 != char2 and char2 != char3 and char3 != char1:
                count = count + 1
        
        return count
            