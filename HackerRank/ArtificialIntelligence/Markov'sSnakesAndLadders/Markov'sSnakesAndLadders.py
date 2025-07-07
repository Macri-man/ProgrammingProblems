import sys
import random

def parse_probabilities(line):
    return list(map(float, line.strip().split(',')))

def parse_counts(line):
    ladders, snakes = line.strip().split(',')
    return int(ladders), int(snakes)

def parse_pairs(line):
    line = line.strip()
    if not line:
        return []
    pairs = line.split()
    result = []
    for p in pairs:
        start, end = p.split(',')
        result.append((int(start), int(end)))
    return result

def prepare_board(ladders, snakes):
    board = list(range(101))
    for start, end in ladders:
        board[start] = end
    for start, end in snakes:
        board[start] = end
    return board

def biased_die_roll(probabilities):
    faces = [1, 2, 3, 4, 5, 6]
    return random.choices(faces, weights=probabilities)[0]

def simulate_game(board, probabilities, max_rolls=1000):
    pos = 1
    rolls = 0
    while pos != 100 and rolls < max_rolls:
        roll = biased_die_roll(probabilities)
        if pos + roll <= 100:
            pos = board[pos + roll]
        rolls += 1
    return rolls if pos == 100 else None

def simulate_multiple_games(board, probabilities, games=5000):
    results = []
    for _ in range(games):
        rolls = simulate_game(board, probabilities)
        if rolls is not None:
            results.append(rolls)
    if not results:
        return -1  # No successful games (shouldn't happen)
    return int(sum(results) / len(results))

def main():
    input_lines = sys.stdin.read().strip().split('\n')
    T = int(input_lines[0].strip())

    idx = 1
    for _ in range(T):
        probabilities = parse_probabilities(input_lines[idx]); idx+=1
        ladder_count, snake_count = parse_counts(input_lines[idx]); idx+=1
        ladders = parse_pairs(input_lines[idx]); idx+=1
        snakes = parse_pairs(input_lines[idx]); idx+=1

        board = prepare_board(ladders, snakes)
        expected_rolls = simulate_multiple_games(board, probabilities)
        print(expected_rolls)

if __name__ == "__main__":
    main()
