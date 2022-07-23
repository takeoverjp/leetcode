/*
 * @lc app=leetcode id=733 lang=rust
 *
 * [733] Flood Fill
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
    pub fn flood_fill(mut image: Vec<Vec<i32>>, sr: i32, sc: i32, color: i32) -> Vec<Vec<i32>> {
        let orig_color = image[sr as usize][sc as usize];
        if orig_color == color {
            return image;
        }
        image[sr as usize][sc as usize] = color;
        Solution::flood_fill_in(&mut image, sr - 1, sc, color, orig_color);
        Solution::flood_fill_in(&mut image, sr + 1, sc, color, orig_color);
        Solution::flood_fill_in(&mut image, sr, sc - 1, color, orig_color);
        Solution::flood_fill_in(&mut image, sr, sc + 1, color, orig_color);
        image
    }
    fn flood_fill_in(image: &mut Vec<Vec<i32>>, sr: i32, sc: i32, color: i32, orig_color: i32) {
        if sr < 0 || sc < 0 || sr as usize >= image.len() || sc as usize >= image[0].len() {
            return;
        }
        let my_color = image[sr as usize][sc as usize];
        if my_color != orig_color || my_color == color {
            return;
        }
        image[sr as usize][sc as usize] = color;
        Solution::flood_fill_in(image, sr - 1, sc, color, orig_color);
        Solution::flood_fill_in(image, sr + 1, sc, color, orig_color);
        Solution::flood_fill_in(image, sr, sc - 1, color, orig_color);
        Solution::flood_fill_in(image, sr, sc + 1, color, orig_color);
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::flood_fill(vec![vec![1, 1, 1], vec![1, 1, 0], vec![1, 0, 1]], 1, 1, 2),
        vec![vec![2, 2, 2], vec![2, 2, 0], vec![2, 0, 1]]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::flood_fill(vec![vec![0, 0, 0], vec![0, 0, 0]], 0, 0, 0),
        vec![vec![0, 0, 0], vec![0, 0, 0]]
    );
}
