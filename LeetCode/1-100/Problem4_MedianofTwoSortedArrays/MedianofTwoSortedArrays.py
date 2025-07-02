class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        x, y = len(nums1), len(nums2)
        low, high = 0, x

        while low <= high:
            cutX = (low + high) // 2
            cutY = (x + y + 1) // 2 - cutX

            leftX = float('-inf') if cutX == 0 else nums1[cutX - 1]
            rightX = float('inf') if cutX == x else nums1[cutX]
            leftY = float('-inf') if cutY == 0 else nums2[cutY - 1]
            rightY = float('inf') if cutY == y else nums2[cutY]

            if leftX <= rightY and leftY <= rightX:
                if (x + y) % 2 == 0:
                    return (max(leftX, leftY) + min(rightX, rightY)) / 2.0
                else:
                    return max(leftX, leftY)
            elif leftX > rightY:
                high = cutX - 1
            else:
                low = cutX + 1