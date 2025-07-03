class Solution:
    def kthCharacter(self, k: int) -> str:
        word = "a"

        while len(word) < k:
            next_part = ''.join(
                chr((ord(c) - ord('a') + 1) % 26 + ord('a')) for c in word
            )
            word += next_part

        return word[k - 1]
    

class Solution:
    def kthCharacter(self, k: int) -> str:
        def find_round(k):
            length = 1
            round = 0
            while length < k:
                round += 1
                length *= 2
            return round
        
        def helper(round: int, index: int) -> str:
            if round == 0:
                return 'a'
            half = 1 << (round - 1)
            if index < half:
                return helper(round - 1, index)
            else:
                prev = helper(round - 1, index - half)
                return chr((ord(prev) - ord('a') + 1) % 26 + ord('a'))

        round = find_round(k)
        return helper(round, k - 1)
