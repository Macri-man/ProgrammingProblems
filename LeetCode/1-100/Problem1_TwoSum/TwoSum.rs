use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new(); // number -> index

        for (i, num) in nums.iter().enumerate() {
            let complement = target - num;
            if let Some(&j) = seen.get(&complement) {
                return vec![j as i32, i as i32];
            }
            seen.insert(num, i);
        }

        vec![] // problem guarantees one solution, so this won't be reached
    }
}
