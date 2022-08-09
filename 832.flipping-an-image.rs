/*
 * @lc app=leetcode id=832 lang=rust
 *
 * [832] Flipping an Image
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
    pub fn flip_and_invert_image(mut image: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = image.len();
        for row in &mut image {
            for i in 0..=((n - 1) / 2) {
                if i == n - i - 1 {
                    row[i] = (row[i] == 0) as i32;
                } else {
                    let tmp = row[i];
                    row[i] = (row[n - i - 1] == 0) as i32;
                    row[n - i - 1] = (tmp == 0) as i32;
                }
            }
        }
        image
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::flip_and_invert_image(vec![vec![1, 1, 0], vec![1, 0, 1], vec![0, 0, 0]]),
        vec![vec![1, 0, 0], vec![0, 1, 0], vec![1, 1, 1]]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::flip_and_invert_image(vec![
            vec![1, 1, 0, 0],
            vec![1, 0, 0, 1],
            vec![0, 1, 1, 1],
            vec![1, 0, 1, 0]
        ]),
        vec![
            vec![1, 1, 0, 0],
            vec![0, 1, 1, 0],
            vec![0, 0, 0, 1],
            vec![1, 0, 1, 0]
        ]
    );
}
