class Solution:
    def calculateMinimumHP(self, dungeon: list[list[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [float('inf')] * n
        dp[n - 1] = max(1, 1 - dungeon[m - 1][n - 1])

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i == m - 1 and j == n - 1:
                    continue
                down = dp[j] if i + 1 < m else float('inf')
                right = dp[j + 1] if j + 1 < n else float('inf')
                need = min(down, right)
                dp[j] = max(1, need - dungeon[i][j])

        return dp[0]
