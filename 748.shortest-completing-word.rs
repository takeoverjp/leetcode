/*
 * @lc app=leetcode id=748 lang=rust
 *
 * [748] Shortest Completing Word
 */

struct Solution;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
    pub right: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

#[macro_export]
macro_rules! list_node {
    () => {
        None
    };
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    pub fn shortest_completing_word(license_plate: String, words: Vec<String>) -> String {
        let mut count = [0; 26];
        license_plate
            .chars()
            .filter_map(|c| {
                if c.is_alphabetic() {
                    Some(c.to_ascii_lowercase())
                } else {
                    None
                }
            })
            .for_each(|c| count[((c as u8) - b'a') as usize] += 1);

        let mut short_word = String::new();
        for word in words.into_iter() {
            let mut copy = [0; 26];
            word.as_bytes()
                .iter()
                .for_each(|&b| copy[(b - b'a') as usize] += 1);

            if count.iter().zip(copy.iter()).all(|(l, w)| *w >= *l)
                && (short_word.is_empty() || short_word.len() > word.len())
            {
                short_word = word;
            }
        }
        short_word
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::shortest_completing_word(
            "1s3 PSt".to_string(),
            vec![
                "step".to_string(),
                "steps".to_string(),
                "stripe".to_string(),
                "stepple".to_string()
            ]
        ),
        "steps".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::shortest_completing_word(
            "1s3 456".to_string(),
            vec![
                "looks".to_string(),
                "pest".to_string(),
                "stew".to_string(),
                "show".to_string()
            ]
        ),
        "pest".to_string()
    );
}
