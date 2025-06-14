
# LeetCode 4: Median of Two Sorted Arrays — Full Step-by-Step Tutorial

---

## Problem Statement

Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n` respectively, return the median of the two sorted arrays. The overall run time complexity should be **O(log (m+n))**.

---

## Example

### Example 1
Input: `nums1 = [1,3]`, `nums2 = [2]`  
Output: `2.00000`  
Explanation: Merged array = `[1,2,3]`, and median is `2`.

### Example 2
Input: `nums1 = [1,2]`, `nums2 = [3,4]`  
Output: `2.50000`  
Explanation: Merged array = `[1,2,3,4]`, and median is `(2 + 3) / 2 = 2.5`.

---

## Constraints

- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

---

## Step-by-Step Guide (Python)

### Step 1: Ensure Binary Search on Smaller Array

```python
def findMedianSortedArrays(nums1, nums2):
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1
```

### Step 2: Initialize Binary Search Variables

```python
    m, n = len(nums1), len(nums2)
    low, high = 0, m
```

### Step 3: Start Binary Search

```python
    while low <= high:
        i = (low + high) // 2
        j = (m + n + 1) // 2 - i
```

### Step 4: Get Border Elements

```python
        maxLeftA = float('-inf') if i == 0 else nums1[i - 1]
        minRightA = float('inf') if i == m else nums1[i]
        
        maxLeftB = float('-inf') if j == 0 else nums2[j - 1]
        minRightB = float('inf') if j == n else nums2[j]
```

### Step 5: Check Correct Partition

```python
        if maxLeftA <= minRightB and maxLeftB <= minRightA:
            if (m + n) % 2 == 0:
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2
            else:
                return max(maxLeftA, maxLeftB)
```

### Step 6: Move Search Space

```python
        elif maxLeftA > minRightB:
            high = i - 1
        else:
            low = i + 1
```

---

## Full Code

```python
def findMedianSortedArrays(nums1, nums2):
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1
        
    m, n = len(nums1), len(nums2)
    low, high = 0, m

    while low <= high:
        i = (low + high) // 2
        j = (m + n + 1) // 2 - i

        maxLeftA = float('-inf') if i == 0 else nums1[i - 1]
        minRightA = float('inf') if i == m else nums1[i]

        maxLeftB = float('-inf') if j == 0 else nums2[j - 1]
        minRightB = float('inf') if j == n else nums2[j]

        if maxLeftA <= minRightB and maxLeftB <= minRightA:
            if (m + n) % 2 == 0:
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2
            else:
                return max(maxLeftA, maxLeftB)
        elif maxLeftA > minRightB:
            high = i - 1
        else:
            low = i + 1
```

---

## Time Complexity

- Binary search on smaller array of length `m` → **O(log(min(m, n)))**
- Space complexity → **O(1)**

---

## Summary

We use a binary search approach to partition both arrays such that the left half contains the smaller elements, and we find the median based on even or odd total length. The key trick is always doing binary search on the **smaller** array to maintain efficiency.
