/*
 * @lc app=leetcode id=819 lang=rust
 *
 * [819] Most Common Word
 */

// @lc code=start
impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        use std::collections::HashMap;
        let mut freq = HashMap::new();

        paragraph
            .split(|ch: char| ch.is_ascii_punctuation() || ch.is_ascii_whitespace())
            .for_each(|word| {
                let word = word.to_ascii_lowercase();
                if !word.is_empty() && !banned.contains(&word) {
                    *freq.entry(word).or_insert(0) += 1;
                }
            });
        freq.iter()
            .max_by(|a, b| a.1.cmp(&b.1))
            .map(|(k, _)| k.to_owned())
            .unwrap()
    }
}
// @lc code=end
