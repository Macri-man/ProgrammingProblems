import heapq
from collections import deque

def solve_n_puzzle(k, board):
    N = k * k - 1
    goal = tuple(range(1, N + 1)) + (0,)  # e.g., (1, 2, 3, 4, ..., 8, 0)

    def manhattan(state):
        distance = 0
        for idx, tile in enumerate(state):
            if tile == 0:
                continue
            goal_row, goal_col = divmod(tile - 1, k)
            curr_row, curr_col = divmod(idx, k)
            distance += abs(goal_row - curr_row) + abs(goal_col - curr_col)
        return distance

    def get_neighbors(state):
        idx = state.index(0)
        row, col = divmod(idx, k)
        neighbors = []
        directions = [(-1, 0, 'UP'), (1, 0, 'DOWN'), (0, -1, 'LEFT'), (0, 1, 'RIGHT')]

        for dr, dc, move in directions:
            new_r, new_c = row + dr, col + dc
            if 0 <= new_r < k and 0 <= new_c < k:
                new_idx = new_r * k + new_c
                lst = list(state)
                lst[idx], lst[new_idx] = lst[new_idx], lst[idx]
                neighbors.append((tuple(lst), move))
        return neighbors

    start = tuple(board)
    heap = [(manhattan(start), 0, start, [])]
    visited = set()

    while heap:
        est_cost, cost, state, path = heapq.heappop(heap)
        if state == goal:
            return path

        if state in visited:
            continue
        visited.add(state)

        for neighbor, move in get_neighbors(state):
            if neighbor not in visited:
                heapq.heappush(heap, (cost + 1 + manhattan(neighbor), cost + 1, neighbor, path + [move]))
    return None


# Read input
k = int(input())
board = [int(input()) for _ in range(k * k)]

solution = solve_n_puzzle(k, board)

# Print result
print(len(solution))
for move in solution:
    print(move)
