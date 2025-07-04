def plusMinus(arr):
    n = len(arr)
    positives = sum(1 for x in arr if x > 0)
    negatives = sum(1 for x in arr if x < 0)
    zeros = sum(1 for x in arr if x == 0)

    print(f"{positives / n:.6f}")
    print(f"{negatives / n:.6f}")
    print(f"{zeros / n:.6f}")
