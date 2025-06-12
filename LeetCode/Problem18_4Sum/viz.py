import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Sorted input array
nums = [-2, -1, 0, 0, 1, 2]
target = 0
n = len(nums)

# Collect frames for animation (i, j, left, right)
fig, ax = plt.subplots()
results = []
frames = []
match = False


for i in range(n - 3):
    if i > 0 and nums[i] == nums[i - 1]:
        total = nums[i] + nums[j] + nums[left] + nums[right]
        frames.append((i, j, left, right, total, match, results.copy()))
        continue
    for j in range(i + 1, n - 2):
        if j > i + 1 and nums[j] == nums[j - 1]:
            total = nums[i] + nums[j] + nums[left] + nums[right]
            frames.append((i, j, left, right, total, match, results.copy()))
            continue
        left, right = j + 1, n - 1
        total = nums[i] + nums[j] + nums[left] + nums[right]
        frames.append((i, j, left, right, total, match, results.copy()))
        while left < right:
            total = nums[i] + nums[j] + nums[left] + nums[right]
            frames.append((i, j, left, right, total, match, results.copy()))
            if total == target:
                left += 1
                right -= 1
                quad = [nums[i], nums[j], nums[left], nums[right]]
                if quad not in results:
                    results.append(quad)
                    match = True
                else:
                    match = False
                frames.append((i, j, left, right, total, match, results.copy()))
                match = False
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                    frames.append((i, j, left, right, total, match, results.copy()))
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
                    frames.append((i, j, left, right, total, match, results.copy()))
            elif total < target:
                left += 1
                frames.append((i, j, left, right, total, match, results.copy()))
            else:
                right -= 1
                frames.append((i, j, left, right, total, match, results.copy()))


def update(frame):
    ax.clear()
    i, j, left, right, total, match, current_results = frame
    positions = list(range(len(nums)))
    ax.set_xlim(-1, len(nums))
    ax.set_ylim(-4, 3)
    ax.set_xticks(positions)
    ax.set_yticks([])
    for pos, num in enumerate(nums):
        ax.text(pos, 0, str(num), ha='center', va='center', fontsize=12, bbox=dict(facecolor='lightgray'))
    ax.annotate('i', xy=(i, 0.5), xytext=(i, 1.4), arrowprops=dict(arrowstyle='->', color='blue'), ha='center', fontsize=10, color='blue')
    ax.annotate('j', xy=(j, 0.5), xytext=(j, 1.1), arrowprops=dict(arrowstyle='->', color='green'), ha='center', fontsize=10, color='green')
    ax.annotate('left', xy=(left, -0.5), xytext=(left, -1.4), arrowprops=dict(arrowstyle='->', color='orange'), ha='center', fontsize=10, color='orange')
    ax.annotate('right', xy=(right, -0.5), xytext=(right, -1.1), arrowprops=dict(arrowstyle='->', color='red'), ha='center', fontsize=10, color='red')
    ax.set_title(f"Trying: {nums[i]} + {nums[j]} + {nums[left]} + {nums[right]} = {total}", fontsize=12)
    if match:
        ax.text(len(nums) // 2, -3.2, f"Match Found!", ha='center', color='darkgreen', fontsize=12, weight='bold')
    ax.text(len(nums) // 2, -3.7, f"Results: {current_results}", ha='center', color='purple', fontsize=10, wrap=True)

# Regenerate animation
ani = animation.FuncAnimation(fig, update, frames=frames, interval=1000, repeat=False)

ani.save('animation.mp4', writer='ffmpeg', fps=1)
ani.save('animation.gif', writer='pillow', fps=1)

plt.show()
