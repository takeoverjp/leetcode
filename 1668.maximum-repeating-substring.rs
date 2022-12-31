/*
 * @lc app=leetcode id=1668 lang=rust
 *
 * [1668] Maximum Repeating Substring
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
    pub fn max_repeating(sequence: String, word: String) -> i32 {
        let mut ans = 0;
        let n1 = sequence.len();
        let n2 = word.len();
        if n1 < n2 {
            return 0;
        }
        let mut streak = 0;
        let mut go_back = false;
        let mut i = 0;
        while i < n1 - n2 + 1 {
            if sequence[i..(i + n2)] == word {
                streak += 1;
                ans = ans.max(streak);
                i += n2;
                go_back = true;
                continue;
            }
            if go_back {
                i -= n2 - 1;
                go_back = false;
            }
            streak = 0;
            i += 1;
        }
        ans
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::max_repeating("ababc".to_string(), "ab".to_string()),
        2
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::max_repeating("ababc".to_string(), "ba".to_string()),
        1
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::max_repeating("ababc".to_string(), "ac".to_string()),
        0
    );
}

#[test]
fn test4() {
    assert_eq!(
        Solution::max_repeating(
            "aaabaaaabaaabaaaabaaaabaaaabaaaaba".to_string(),
            "aaaba".to_string()
        ),
        5
    );
}

#[test]
fn test5() {
    assert_eq!(
        Solution::max_repeating("a".to_string(), "aaa".to_string()),
        0
    );
}
