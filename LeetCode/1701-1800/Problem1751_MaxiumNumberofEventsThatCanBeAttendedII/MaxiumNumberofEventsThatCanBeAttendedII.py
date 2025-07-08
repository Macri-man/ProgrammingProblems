class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n = len(events)
        events.sort(key=lambda x: x[1])  
        
        prev = []
        for i in range(n):
            left, right = 0, i - 1
            result = -1
            while left <= right:
                mid = (left + right) >> 1
                if events[mid][1] < events[i][0]:
                    result = mid
                    left = mid + 1
                else:
                    right = mid - 1
            prev.append(result)
        
        prev_row = [0] * (k + 1)
        curr_row = [0] * (k + 1)
        
        for i in range(n):
            value = events[i][2]
            
            for j in range(k + 1):
                curr_row[j] = prev_row[j]
                
                if j > 0:
                    if prev[i] == -1:
                        curr_row[j] = max(curr_row[j], value)
                    else:
                        pass
            
            prev_row, curr_row = curr_row, prev_row
        
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            value = events[i - 1][2]
            
            for j in range(k + 1):
                dp[i][j] = dp[i - 1][j]
                
                if j > 0:
                    if prev[i - 1] == -1:
                        dp[i][j] = max(dp[i][j], value)
                    else:
                        dp[i][j] = max(dp[i][j], dp[prev[i - 1] + 1][j - 1] + value)
        
        return dp[n][k]