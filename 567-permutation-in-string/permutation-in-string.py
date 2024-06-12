class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        s1_count = Counter(s1) 
        
        for i in range(n2 - n1 + 1):
            window = s2[i:i+n1]  
            window_count = Counter(window) 
            
            if window_count == s1_count:
                return True
                
        return False