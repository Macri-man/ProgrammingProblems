class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        matrix = [[-1 for _ in range(n)] for _ in range(m)]
        
        top, bottom = 0, m - 1
        left, right = 0, n - 1

        while head and top <= bottom and left <= right:
            for j in range(left, right + 1):
                if not head:
                    return matrix
                matrix[top][j] = head.val
                head = head.next
            top += 1

            for i in range(top, bottom + 1):
                if not head:
                    return matrix
                matrix[i][right] = head.val
                head = head.next
            right -= 1

            for j in range(right, left - 1, -1):
                if not head:
                    return matrix
                matrix[bottom][j] = head.val
                head = head.next
            bottom -= 1

            for i in range(bottom, top - 1, -1):
                if not head:
                    return matrix
                matrix[i][left] = head.val
                head = head.next
            left += 1

        return matrix
