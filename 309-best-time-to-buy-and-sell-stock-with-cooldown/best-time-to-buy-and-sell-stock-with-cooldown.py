class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        mem = {}

        def dfs(i, holding):
            # base
            if i >= n:
                return 0
            
            if (i, holding) in mem:
                return mem[(i, holding)]

            # main
            if holding: # whether the person buys or not
                # sell/ hold
                sell = prices[i] + dfs(i+2, False) # buy
                hold = dfs(i+1, True) #skip
                mem[(i, holding)] = max(sell, hold)
            else:
                # buy/ skip
                buy = -prices[i] + dfs(i+1, True) # buy
                skip = dfs(i+1, False) #skip
                mem[(i, holding)] = max(buy, skip)
            
            return mem[(i, holding)]

        return dfs(0, False)  # i