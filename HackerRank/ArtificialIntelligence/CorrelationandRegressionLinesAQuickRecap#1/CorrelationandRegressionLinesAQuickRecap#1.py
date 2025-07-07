physics = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]

n = len(physics)

mean_x = sum(physics) / n
mean_y = sum(history) / n

numerator = 0
denominator_x = 0
denominator_y = 0

for i in range(n):
    diff_x = physics[i] - mean_x
    diff_y = history[i] - mean_y
    numerator += diff_x * diff_y
    denominator_x += diff_x ** 2
    denominator_y += diff_y ** 2

correlation = numerator / ((denominator_x**0.5) * (denominator_y**0.5))

# Print rounded to 3 decimals
print(f"{correlation:.3f}")