class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return "0"
        # pseudo
        # reverse 
        num1 = num1[::-1]
        num2 = num2[::-1]

        # res array = (len(num1) + len(nums))
        res = [0] * (len(num1) + len(num2))

        for i in range(len(num1)):
            for j in range (len(num2)):
                product = int(num1[i]) * int(num2[j])
                res[i+j] += product
                # handle carry
                res[i+j+1] += res[i+j] // 10 
                res[i+j] %= 10 
        
        # check if there are leading zeros
        # remove
        while len(res) > 1 and res[-1] == 0:
            res.pop()

        # reverse the ans and return it
        return ''.join(map(str, res[::-1]))