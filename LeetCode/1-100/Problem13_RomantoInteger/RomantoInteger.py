class Solution:
    def romanToInt(self, s: str) -> int:
        table = {
            'I': 1, 'V': 5, 'X': 10,
            'L': 50, 'C': 100,
            'D': 500, 'M': 1000
        }

        total = 0
        n = len(s)
        for i in range(n):
            curr = table[s[i]]
            next_val = table[s[i + 1]] if i + 1 < n else 0
            if curr < next_val:
                total -= curr
            else:
                total += curr
        return total