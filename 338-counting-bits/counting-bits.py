class Solution:
    def countBits(self, n: int) -> List[int]:
        res=[]
        for i in range(n+1):
            bits = 0
            idx = i
            while idx:
                idx = idx & (idx-1)
                bits+=1
            res.append(bits)
        
        return res
        