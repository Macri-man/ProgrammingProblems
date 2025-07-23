from typing import List

class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        total = rows * cols
        result = [[rStart, cStart]]
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        r, c = rStart, cStart
        step = 1
        count = 1

        def in_bounds(r, c):
            return 0 <= r < rows and 0 <= c < cols

        while count < total:
            for i in range(4):
                dx, dy = directions[i]
                for _ in range(step):
                    r += dx
                    c += dy
                    if in_bounds(r, c):
                        result.append([r, c])
                        count += 1
                        if count == total:
                            return result
                if i % 2 == 1:
                    step += 1

        return result
