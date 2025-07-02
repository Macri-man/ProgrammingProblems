
class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        MOD = 10**9 + 7

        from collections import deque

        n = len(word)
        groups = []
        i = 0
        while i < n:
            j = i
            while j < n and word[j] == word[i]:
                j += 1
            groups.append(j - i)
            i = j

        max_len = n
        dp = [0] * (max_len + 1)
        dp[0] = 1

        for group_len in groups:
            new_dp = [0] * (max_len + 1)
            prefix = [0] * (max_len + 2)

            for i in range(max_len + 1):
                prefix[i + 1] = (prefix[i] + dp[i]) % MOD

            for i in range(max_len + 1):
                if i - group_len >= 0:
                    new_dp[i] = (prefix[i] - prefix[i - group_len]) % MOD
                else:
                    new_dp[i] = prefix[i]
            dp = new_dp

        return sum(dp[k:]) % MOD


def main():
    sol = Solution()

    # Example 1
    word1 = "aabbccdd"
    k1 = 7
    print(sol.possibleStringCount(word1, k1))  # Output: 5

    # Example 2
    word2 = "aabbccdd"
    k2 = 8
    print(sol.possibleStringCount(word2, k2))  # Output: 1

    # Example 3
    word3 = "aaabbb"
    k3 = 3
    print(sol.possibleStringCount(word3, k3))  # Output: 8

if __name__ == "__main__":
    main()
