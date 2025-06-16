use std::collections::{HashMap, HashSet};

pub struct Solution;

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let n = nums.len();
        let mut pair_sum: HashMap<i32, Vec<(usize, usize)>> = HashMap::new();
        let mut result: HashSet<Vec<i32>> = HashSet::new();

        for i in 0..n {
            for j in i + 1..n {
                pair_sum.entry(nums[i] + nums[j]).or_default().push((i, j));
            }
        }

        for (&sum1, pairs1) in &pair_sum {
            let sum2 = target - sum1;
            if let Some(pairs2) = pair_sum.get(&sum2) {
                for &(i, j) in pairs1 {
                    for &(k, l) in pairs2 {
                        let indices = [i, j, k, l];
                        let mut unique = indices.to_vec();
                        unique.sort_unstable();
                        unique.dedup();
                        if unique.len() == 4 {
                            let mut quad = vec![nums[i], nums[j], nums[k], nums[l]];
                            quad.sort_unstable();
                            result.insert(quad);
                        }
                    }
                }
            }
        }

        result.into_iter().collect()
    }
}
