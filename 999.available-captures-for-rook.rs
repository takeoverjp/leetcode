/*
 * @lc app=leetcode id=999 lang=rust
 *
 * [999] Available Captures for Rook
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
    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        for i in 0..board.len() {
            for j in 0..board[i].len() {
                if board[i][j] == 'R' {
                    return Solution::cap(&board, i as i32, j as i32, 0, 1)
                        + Solution::cap(&board, i as i32, j as i32, 0, -1)
                        + Solution::cap(&board, i as i32, j as i32, 1, 0)
                        + Solution::cap(&board, i as i32, j as i32, -1, 0);
                }
            }
        }
        0
    }

    fn cap(b: &Vec<Vec<char>>, mut x: i32, mut y: i32, dx: i32, dy: i32) -> i32 {
        while x >= 0
            && x < b.len() as i32
            && y >= 0
            && y < b[x as usize].len() as i32
            && b[x as usize][y as usize] != 'B'
        {
            if b[x as usize][y as usize] == 'p' {
                return 1;
            }
            x += dx;
            y += dy;
        }
        0
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::num_rook_captures(vec![
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', '.', '.', 'p', '.', '.', '.', '.'],
            vec!['.', '.', '.', 'R', '.', '.', '.', 'p'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', '.', '.', 'p', '.', '.', '.', '.'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.']
        ]),
        3
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::num_rook_captures(vec![
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', 'p', 'p', 'p', 'p', 'p', '.', '.'],
            vec!['.', 'p', 'p', 'B', 'p', 'p', '.', '.'],
            vec!['.', 'p', 'B', 'R', 'B', 'p', '.', '.'],
            vec!['.', 'p', 'p', 'B', 'p', 'p', '.', '.'],
            vec!['.', 'p', 'p', 'p', 'p', 'p', '.', '.'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.']
        ]),
        0
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::num_rook_captures(vec![
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', '.', '.', 'p', '.', '.', '.', '.'],
            vec!['.', '.', '.', 'p', '.', '.', '.', '.'],
            vec!['p', 'p', '.', 'R', '.', 'p', 'B', '.'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.'],
            vec!['.', '.', '.', 'B', '.', '.', '.', '.'],
            vec!['.', '.', '.', 'p', '.', '.', '.', '.'],
            vec!['.', '.', '.', '.', '.', '.', '.', '.']
        ]),
        3
    );
}
