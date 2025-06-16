func fourSum(nums []int, target int) [][]int {
	n := len(nums)
	sort.Ints(nums)
	pairMap := map[int][][]int{}
	result := map[[4]int]struct{}{}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			sum := nums[i] + nums[j]
			pairMap[sum] = append(pairMap[sum], []int{i, j})
		}
	}

	for sum1, pairs1 := range pairMap {
		sum2 := target - sum1
		pairs2, ok := pairMap[sum2]
		if !ok {
			continue
		}
		for _, p1 := range pairs1 {
			for _, p2 := range pairs2 {
				i, j, k, l := p1[0], p1[1], p2[0], p2[1]
				if i == k || i == l || j == k || j == l {
					continue
				}
				quad := []int{nums[i], nums[j], nums[k], nums[l]}
				sort.Ints(quad)
				result[[4]int{quad[0], quad[1], quad[2], quad[3]}] = struct{}{}
			}
		}
	}

	res := [][]int{}
	for k := range result {
		res = append(res, []int{k[0], k[1], k[2], k[3]})
	}
	return res
}
