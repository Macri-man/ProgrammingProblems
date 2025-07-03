impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (a, b) = if nums1.len() <= nums2.len() {
            (nums1, nums2)
        } else {
            (nums2, nums1)
        };

        let m = a.len();
        let n = b.len();
        let mut low = 0;
        let mut high = m;

        while low <= high {
            let partition_a = (low + high) / 2;
            let partition_b = (m + n + 1) / 2 - partition_a;

            let max_left_a = if partition_a == 0 {
                i32::MIN
            } else {
                a[partition_a - 1]
            };

            let min_right_a = if partition_a == m {
                i32::MAX
            } else {
                a[partition_a]
            };

            let max_left_b = if partition_b == 0 {
                i32::MIN
            } else {
                b[partition_b - 1]
            };

            let min_right_b = if partition_b == n {
                i32::MAX
            } else {
                b[partition_b]
            };

            if max_left_a <= min_right_b && max_left_b <= min_right_a {
                if (m + n) % 2 == 0 {
                    return (f64::from(max_left_a.max(max_left_b))
                        + f64::from(min_right_a.min(min_right_b)))
                        / 2.0;
                } else {
                    return f64::from(max_left_a.max(max_left_b));
                }
            } else if max_left_a > min_right_b {
                high = partition_a - 1;
            } else {
                low = partition_a + 1;
            }
        }
        panic!("Input arrays are not sorted or invalid.");
    }
}
