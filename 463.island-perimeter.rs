/*
 * @lc app=leetcode id=463 lang=rust
 *
 * [463] Island Perimeter
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
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut ret = 0;
        let row = grid.len();
        let col = grid[0].len();
        for i in 0..row {
            for j in 0..col {
                if grid[i][j] == 1 {
                    if (j == 0) || (grid[i][j - 1] == 0) {
                        ret += 1;
                    }
                    if (j == col - 1) || (grid[i][j + 1] == 0) {
                        ret += 1;
                    }
                    if (i == 0) || (grid[i - 1][j] == 0) {
                        ret += 1;
                    }
                    if (i == row - 1) || (grid[i + 1][j] == 0) {
                        ret += 1;
                    }
                }
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::island_perimeter(vec![
            vec![0, 1, 0, 0],
            vec![1, 1, 1, 0],
            vec![0, 1, 0, 0],
            vec![1, 1, 0, 0]
        ]),
        16
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::island_perimeter(vec![vec![1]]), 4);
}
#[test]
fn test3() {
    assert_eq!(Solution::island_perimeter(vec![vec![1, 0]]), 4);
}
