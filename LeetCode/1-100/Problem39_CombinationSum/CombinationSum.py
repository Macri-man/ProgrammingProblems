class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        self.backtrack(candidates, target, 0, [], result)
        return result

    def backtrack(self, candidates, target, start, current, result):
        if target == 0:
            result.append(list(current))
            return
        if target < 0:
            return

        for i in range(start, len(candidates)):
            current.append(candidates[i])
            self.backtrack(candidates, target - candidates[i], i, current, result) 
            current.pop() 