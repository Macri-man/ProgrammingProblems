use std::collections::VecDeque;

pub struct Solution;

impl Solution {
    pub fn possible_string_count(word: &str, k: usize) -> i64 {
        const MOD: i64 = 1_000_000_007;
        let chars: Vec<char> = word.chars().collect();
        let n = chars.len();

        // Group consecutive characters
        let mut groups = Vec::new();
        let mut i = 0;
        while i < n {
            let mut j = i;
            while j < n && chars[j] == chars[i] {
                j += 1;
            }
            groups.push(j - i);
            i = j;
        }

        let total_len = n;
        if k > total_len {
            return 0;
        }

        let mut dp = vec![0i64; total_len + 1];
        dp[0] = 1;

        for &group_len in &groups {
            let mut new_dp = vec![0i64; total_len + 1];
            let mut window_sum: i64 = 0;
            let mut window: VecDeque<i64> = VecDeque::new();

            for i in 1..=total_len {
                let add_val = dp[i - 1];
                window.push_back(add_val);
                window_sum = (window_sum + add_val) % MOD;

                if i > group_len {
                    let removed = window.pop_front().unwrap();
                    window_sum = (window_sum - removed + MOD) % MOD;
                }

                new_dp[i] = window_sum;
            }

            dp = new_dp;
        }

        dp[k..=total_len]
            .iter()
            .fold(0, |acc, &val| (acc + val) % MOD)
    }
}

fn main() {
    let param_1 = String::from("aaabbb");
    let param_2 = 3;

    // Correct borrow and cast
    let ret = Solution::possible_string_count(&param_1, param_2 as usize);
    println!("Output: {}", ret); // Expected: 8

    let param_3 = "a".repeat(962) + &"b".repeat(962);
    let param_4 = 1924;
    let ret2 = Solution::possible_string_count(&param_3, param_4 as usize);
    println!("Output: {}", ret2); // Expected: 1
}
