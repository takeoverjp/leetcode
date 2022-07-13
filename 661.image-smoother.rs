/*
 * @lc app=leetcode id=661 lang=rust
 *
 * [661] Image Smoother
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
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let w = img[0].len();
        let h = img.len();
        let mut ret = Vec::<Vec<i32>>::new();
        ret.resize(h, Vec::<i32>::new());
        for row in ret.iter_mut() {
            row.resize(w, 0);
        }
        for x in 0..w {
            for y in 0..h {
                let mut count = 1;
                let mut sum = img[y][x] as i64;
                if y >= 1 {
                    sum += img[y - 1][x] as i64;
                    count += 1;
                }
                if y + 2 <= h {
                    sum += img[y + 1][x] as i64;
                    count += 1;
                }
                if x >= 1 {
                    if y >= 1 {
                        sum += img[y - 1][x - 1] as i64;
                        count += 1;
                    }
                    if y + 2 <= h {
                        sum += img[y + 1][x - 1] as i64;
                        count += 1;
                    }
                    sum += img[y][x - 1] as i64;
                    count += 1;
                }
                if x + 2 <= w {
                    if y >= 1 {
                        sum += img[y - 1][x + 1] as i64;
                        count += 1;
                    }
                    if y + 2 <= h {
                        sum += img[y + 1][x + 1] as i64;
                        count += 1;
                    }
                    sum += img[y][x + 1] as i64;
                    count += 1;
                }
                ret[y][x] = (sum / count) as i32;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::image_smoother(vec![vec![1, 1, 1], vec![1, 0, 1], vec![1, 1, 1]]),
        vec![vec![0, 0, 0], vec![0, 0, 0], vec![0, 0, 0]]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::image_smoother(vec![
            vec![100, 200, 100],
            vec![200, 50, 200],
            vec![100, 200, 100]
        ]),
        vec![
            vec![137, 141, 137],
            vec![141, 138, 141],
            vec![137, 141, 137]
        ]
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::image_smoother(vec![vec![1],]), vec![vec![1],]);
}
