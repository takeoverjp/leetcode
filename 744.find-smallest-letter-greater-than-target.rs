/*
 * @lc app=leetcode id=744 lang=rust
 *
 * [744] Find Smallest Letter Greater Than Target
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
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        if target < letters[0] {
            return letters[0];
        }
        for letter in &letters {
            if *letter > target {
                return *letter;
            }
        }
        letters[0]
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'a'),
        'c'
    );
    assert_eq!(
        Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'c'),
        'f'
    );
    assert_eq!(
        Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'd'),
        'f'
    );
    assert_eq!(
        Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'g'),
        'j'
    );
    assert_eq!(
        Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'k'),
        'c'
    );
}
