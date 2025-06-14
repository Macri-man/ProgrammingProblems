
# 🧮 LeetCode Problem 18: 4Sum

**Difficulty:** Medium  
**Topics:** Array, Two Pointers, Sorting

---

## 📘 Problem Statement

Given an array `nums` of `n` integers, return **all unique quadruplets** `[nums[a], nums[b], nums[c], nums[d]]` such that:

- `0 <= a, b, c, d < n`
- `a`, `b`, `c`, and `d` are distinct
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

---

### 🔍 Example 1

**Input:**
```python
nums = [1, 0, -1, 0, -2, 2]
target = 0
```

**Output:**
```python
[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
```

---

### 🔍 Example 2

**Input:**
```python
nums = [2, 2, 2, 2, 2]
target = 8
```

**Output:**
```python
[[2, 2, 2, 2]]
```

---

## ✅ Constraints

- `1 <= nums.length <= 200`
- `-10⁹ <= nums[i] <= 10⁹`
- `-10⁹ <= target <= 10⁹`

---

## 🧠 Strategy

1. **Sort the array** to simplify duplicate handling and enable two-pointer optimization.
2. Use two nested loops to fix the first two numbers (`i`, `j`).
3. For each pair, use the **two-pointer** technique (`left`, `right`) to find remaining pairs.
4. **Skip duplicates** carefully in all four positions.

---

## 🧑‍💻 Python Code

```python
def fourSum(nums, target):
    nums.sort()
    quadruplets = []
    n = len(nums)

    for i in range(n - 3):
        if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicates for i
            continue

        for j in range(i + 1, n - 2):
            if j > i + 1 and nums[j] == nums[j - 1]:  # Skip duplicates for j
                continue

            left, right = j + 1, n - 1

            while left < right:
                total = nums[i] + nums[j] + nums[left] + nums[right]

                if total == target:
                    quadruplets.append([nums[i], nums[j], nums[left], nums[right]])
                    left += 1
                    right -= 1

                    while left < right and nums[left] == nums[left - 1]:  # Skip duplicates for left
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:  # Skip duplicates for right
                        right -= 1

                elif total < target:
                    left += 1
                else:
                    right -= 1

    return quadruplets
```

---

## 🧪 Sample Usage

```python
print(fourSum([1, 0, -1, 0, -2, 2], 0))
# Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

print(fourSum([2, 2, 2, 2, 2], 8))
# Output: [[2, 2, 2, 2]]
```

---

## ⏱️ Time & Space Complexity

| Metric             | Value             |
|--------------------|-------------------|
| Time Complexity     | `O(n^3)`          |
| Space Complexity    | `O(1)` (excluding output) |

---
