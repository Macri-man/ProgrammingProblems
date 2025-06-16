
# LeetCode 23: Merge k Sorted Lists — Step-by-Step Guide

## 🧩 Problem Statement

You are given an array of `k` linked lists. Each list is sorted in ascending order. Merge all the lists into one sorted linked list and return it.

## 🧠 Approach: Min-Heap (Priority Queue)

We use a **min-heap** to always extract the smallest current node from all the heads of the lists.

## 🧮 Time and Space Complexity

- **Time**: O(N log k), where N is the total number of nodes.
- **Space**: O(k) for the heap.

## 🔧 Step-by-Step Solution (Python)

```python
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __lt__(self, other):
        return self.val < other.val

def mergeKLists(lists):
    heap = []

    for node in lists:
        if node:
            heapq.heappush(heap, node)

    dummy = ListNode(0)
    current = dummy

    while heap:
        node = heapq.heappop(heap)
        current.next = node
        current = current.next

        if node.next:
            heapq.heappush(heap, node.next)

    return dummy.next
```

## ✅ Examples

### Example 1
**Input**: `lists = [[1,4,5],[1,3,4],[2,6]]`  
**Output**: `1->1->2->3->4->4->5->6`

### Example 2
**Input**: `lists = []`  
**Output**: `[]`

### Example 3
**Input**: `lists = [[]]`  
**Output**: `[]`

## 📌 Notes

- Define a custom comparator (`__lt__`) in `ListNode` to use `heapq` with custom objects.
- Check if nodes are not `None` before pushing to the heap.
