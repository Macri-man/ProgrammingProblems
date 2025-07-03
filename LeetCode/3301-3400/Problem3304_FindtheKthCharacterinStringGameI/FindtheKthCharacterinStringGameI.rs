impl Solution {
    pub fn kth_character(k: i32) -> char {
        let mut word = String::from("a");

        while word.len() < k as usize {
            let next_part: String = word
                .chars()
                .map(|c| ((c as u8 - b'a' + 1) % 26 + b'a') as char)
                .collect();
            word.push_str(&next_part);
        }

        word.chars().nth((k - 1) as usize).unwrap()
    }
}
