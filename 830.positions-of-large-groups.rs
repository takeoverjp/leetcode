/*
 * @lc app=leetcode id=830 lang=rust
 *
 * [830] Positions of Large Groups
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
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        let mut ret: Vec<Vec<i32>> = Vec::new();
        let len = s.len();
        let mut last = '\0';
        let mut count = 0;
        let s = s.chars().collect::<Vec<char>>();
        for (i, c) in s.iter().enumerate() {
            if *c == last {
                count += 1;
                if i == len - 1 {
                    if count >= 3 {
                        ret.push(vec![len as i32 - count, len as i32 - 1]);
                    }
                    return ret;
                }
            } else {
                if count >= 3 {
                    ret.push(vec![i as i32 - count, i as i32 - 1]);
                }
                count = 1;
                last = *c;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::large_group_positions("abbxxxxzzy".to_string()),
        vec![vec![3, 6]]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::large_group_positions("abc".to_string()),
        Vec::<Vec<i32>>::new()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::large_group_positions("abcdddeeeeaabbbcd".to_string()),
        vec![vec![3, 5], vec![6, 9], vec![12, 14]]
    );
}
