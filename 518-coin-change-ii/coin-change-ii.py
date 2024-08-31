class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # memoization
        # 1
        mem = {}

        # self.ans = 0

        def dfs(ind, total):
            # base
            if total == 0:
                return 1
            
            if ind >= len(coins) or total < 0:
                return 0

            # <---- #2
            if (ind, total) in mem:
                return mem[(ind, total)]

            # 3 dtore
            mem[(ind, total)] = dfs(ind, total-coins[ind]) + dfs(ind+1, total)

            return mem[(ind, total)]



        return dfs(0, amount) # ind, amount





# problem underst. -> 50% tick

# naive approach -> 25% tick

# optimized app + pseudo code -> 20% tick

# code -> 5% 