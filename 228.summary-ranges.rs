/*
 * @lc app=leetcode id=228 lang=rust
 *
 * [228] Summary Ranges
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

#[macro_export]
macro_rules! list_node {
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    fn summarize(start: i32, end: i32) -> String {
        if start == end {
            return start.to_string();
        } else {
            return start.to_string() + "->" + &end.to_string();
        }
    }
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut start = std::i32::MIN;
        let mut end = std::i32::MIN;
        let mut ret = Vec::<String>::new();
        for i in 0..nums.len() {
            if i == nums.len() - 1 {
                if i == 0 {
                    ret.push(Solution::summarize(nums[i], nums[i]));
                } else if nums[i] == end + 1 {
                    end = nums[i];
                    ret.push(Solution::summarize(start, end));
                } else {
                    ret.push(Solution::summarize(start, end));
                    ret.push(nums[i].to_string());
                }
                return ret;
            }

            if i == 0 {
                start = nums[i];
                end = start;
                continue;
            }

            if nums[i] == end + 1 {
                end = nums[i];
                continue;
            }

            ret.push(Solution::summarize(start, end));
            start = nums[i];
            end = start;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::summary_ranges(vec![0, 1, 2, 4, 5, 7]),
        vec!["0->2", "4->5", "7"]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::summary_ranges(vec![0, 2, 3, 4, 6, 8, 9]),
        vec!["0", "2->4", "6", "8->9"]
    );
}
