class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        count = 0

        # iterate the s
        for i in range(len(s) - 2):
            # acquire the sub string
            char1 = s[i]
            char2 = s[i + 1]
            char3 = s[i + 2]

            # check if the substring is good
            if char1 != char2 and char2 != char3 and char3 != char1:
                # good substring
                count = count + 1 
            
            # automatically bad -> ignore
        
        return count

            
        


# statement done
# basic approach done
# question
# let's try to code
        
        