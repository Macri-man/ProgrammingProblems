
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result = []

        def backtrack(start: int, current: List[int], target: int):
            if len(current) == k:
                if target == 0:
                    result.append(current[:])
                return
            
            for i in range(start, 10):
                if i > target:
                    break  
                current.append(i)
                backtrack(i + 1, current, target - i)
                current.pop() 

        backtrack(1, [], n)
        return result