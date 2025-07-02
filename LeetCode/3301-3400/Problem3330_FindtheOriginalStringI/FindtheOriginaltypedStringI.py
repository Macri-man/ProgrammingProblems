class Solution:
    def possibleStringCount(self, word: str) -> int:
        count = 1 
        n = len(word)
        i = 0

        while i < n:
            j = i + 1
            while j < n and word[j] == word[i]:
                j += 1
            group_len = j - i
            if group_len > 1:
                count += group_len - 1
            i = j

        return count
