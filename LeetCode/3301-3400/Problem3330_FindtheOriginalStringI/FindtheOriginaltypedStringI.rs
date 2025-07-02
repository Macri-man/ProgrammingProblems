impl Solution {
    pub fn possible_string_count(word: String) -> i32 {
        let bytes = word.as_bytes();
        let mut count = 1; // original string is always valid
        let mut i = 0;

        while i < bytes.len() {
            let mut j = i + 1;
            while j < bytes.len() && bytes[j] == bytes[i] {
                j += 1;
            }
            let group_len = j - i;
            if group_len > 1 {
                count += (group_len - 1) as i32;
            }
            i = j;
        }

        count
    }
}
