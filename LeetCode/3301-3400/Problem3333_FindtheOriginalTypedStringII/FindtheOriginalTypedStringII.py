MOD = 10**9 + 7

def groups_to_poly(groups):
    max_sum = sum(g - 1 for g in groups)
    dp = [0] * (max_sum + 1)
    dp[0] = 1

    new_dp = [0] * (max_sum + 1)
    prefix = [0] * (max_sum + 2)  # prefix sums

    for g in groups:
        bound = g - 1
        running_sum = 0

        # Compute prefix sums with rolling window to optimize dp update
        # Reuse prefix array to avoid reallocation
        prefix[0] = 0
        for i in range(len(dp)):
            prefix[i+1] = (prefix[i] + dp[i]) % MOD

        for i in range(len(dp)):
            left = i - bound
            if left < 0:
                left = 0
            # sum dp[left..i] = prefix[i+1] - prefix[left]
            val = prefix[i+1] - prefix[left]
            # Avoid negative modulo:
            if val < 0:
                val += MOD
            new_dp[i] = val

        dp, new_dp = new_dp, dp  # swap references to reuse lists, avoid allocations

    return dp

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        groups = []
        count = 1
        for i in range(1, len(word)):
            if word[i] == word[i-1]:
                count += 1
            else:
                groups.append(count)
                count = 1
        groups.append(count)

        m = len(groups)
        total = sum(groups)

        if k <= m:
            res = 1
            for g in groups:
                res = (res * g) % MOD
            return res

        if k > total:
            return 0

        target = k - m
        mid = m // 2

        dp_left = groups_to_poly(groups[:mid])
        dp_right = groups_to_poly(groups[mid:])

        # Precompute prefix sums for dp_right once
        prefix_right = [0] * (len(dp_right) + 1)
        for i in range(len(dp_right)):
            prefix_right[i+1] = (prefix_right[i] + dp_right[i]) % MOD

        result = 0
        for s, val in enumerate(dp_left):
            need = target - s
            if need <= 0:
                result += val * prefix_right[-1]
            elif need < len(dp_right):
                result += val * (prefix_right[-1] - prefix_right[need])
            result %= MOD

        return result
