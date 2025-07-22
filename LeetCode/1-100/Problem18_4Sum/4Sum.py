from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        n = len(nums)
        if n < 4:
            return result

        nums.sort()

        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            min1 = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]
            if min1 > target:
                break
            max1 = nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3]
            if max1 < target:
                continue

            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                min2 = nums[i] + nums[j] + nums[j + 1] + nums[j + 2]
                if min2 > target:
                    break
                max2 = nums[i] + nums[j] + nums[n - 1] + nums[n - 2]
                if max2 < target:
                    continue

                left, right = j + 1, n - 1
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    if total == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        left_val, right_val = nums[left], nums[right]
                        while left < right and nums[left] == left_val:
                            left += 1
                        while left < right and nums[right] == right_val:
                            right -= 1
                    elif total < target:
                        left += 1
                    else:
                        right -= 1

        return result
