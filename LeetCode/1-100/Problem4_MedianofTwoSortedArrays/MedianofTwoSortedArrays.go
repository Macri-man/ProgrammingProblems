package main

import (
	"math"
)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	// Ensure nums1 is the smaller array
	if len(nums1) > len(nums2) {
		return findMedianSortedArrays(nums2, nums1)
	}

	x, y := len(nums1), len(nums2)
	low, high := 0, x

	for low <= high {
		partitionX := (low + high) / 2
		partitionY := (x+y+1)/2 - partitionX

		maxLeftX := math.Inf(-1)
		if partitionX != 0 {
			maxLeftX = float64(nums1[partitionX-1])
		}

		minRightX := math.Inf(1)
		if partitionX != x {
			minRightX = float64(nums1[partitionX])
		}

		maxLeftY := math.Inf(-1)
		if partitionY != 0 {
			maxLeftY = float64(nums2[partitionY-1])
		}

		minRightY := math.Inf(1)
		if partitionY != y {
			minRightY = float64(nums2[partitionY])
		}

		if maxLeftX <= minRightY && maxLeftY <= minRightX {
			if (x+y)%2 == 0 {
				return (math.Max(maxLeftX, maxLeftY) + math.Min(minRightX, minRightY)) / 2.0
			} else {
				return math.Max(maxLeftX, maxLeftY)
			}
		} else if maxLeftX > minRightY {
			high = partitionX - 1
		} else {
			low = partitionX + 1
		}
	}

}
