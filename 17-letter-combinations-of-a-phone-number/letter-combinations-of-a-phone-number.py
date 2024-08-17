class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"]
        }

        ans = []

        if not digits:
            return ans
        
        # backtrack
        def backtrack(indx,temp_ans ):
            # base condition
            if indx >= len(digits):
                ans.append("".join(temp_ans))
                return

            # main logic
            digit = digits[indx] # 2
            letters = phone[digit]

            # loop
            for i in letters:
                temp_ans.append(i)
                backtrack(indx+1, temp_ans)
                temp_ans.pop()
            
        backtrack(0, [])
        
        return ans





