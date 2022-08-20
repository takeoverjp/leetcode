/*
 * @lc app=leetcode id=892 lang=rust
 *
 * [892] Surface Area of 3D Shapes
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
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        Solution::xy(&grid) + Solution::yz(&grid) + Solution::zx(&grid)
    }

    fn xy(grid: &Vec<Vec<i32>>) -> i32 {
        let mut ret = 0;
        for row in grid {
            for v in row {
                if *v > 0 {
                    ret += 1;
                }
            }
        }
        ret * 2
    }
    fn yz(grid: &Vec<Vec<i32>>) -> i32 {
        let mut ret = 0;
        let size = grid.len();
        for row in grid {
            ret += row[0] + row[size - 1];
            for x in 1..size {
                ret += (row[x] - row[x - 1]).abs();
            }
        }
        ret
    }
    fn zx(grid: &Vec<Vec<i32>>) -> i32 {
        let mut ret = 0;
        let size = grid.len();
        for x in 0..size {
            ret += grid[0][x] + grid[size - 1][x];
            for y in 1..size {
                ret += (grid[y][x] - grid[y - 1][x]).abs();
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::surface_area(vec![vec![1, 2], vec![3, 4]]), 34);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::surface_area(vec![vec![1, 1, 1], vec![1, 0, 1], vec![1, 1, 1]]),
        32
    );
    assert_eq!(
        Solution::surface_area(vec![vec![2, 2, 2], vec![2, 1, 2], vec![2, 2, 2]]),
        46
    );
}
