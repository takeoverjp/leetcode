/*
 * @lc app=leetcode id=706 lang=rust
 *
 * [706] Design HashMap
 */

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
use std::collections::HashMap;
struct MyHashMap {
    map: HashMap<i32, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashMap {
    fn new() -> Self {
        MyHashMap {
            map: HashMap::<i32, i32>::new(),
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        self.map.insert(key, value);
    }

    fn get(&self, key: i32) -> i32 {
        match self.map.get(&key) {
            Some(n) => *n,
            _ => -1,
        }
    }

    fn remove(&mut self, key: i32) {
        self.map.remove(&key);
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * let obj = MyHashMap::new();
 * obj.put(key, value);
 * let ret_2: i32 = obj.get(key);
 * obj.remove(key);
 */
// @lc code=end

#[test]
fn test1() {
    let mut obj = MyHashMap::new();
    obj.put(1, 1);
    obj.put(2, 2);

    assert_eq!(obj.get(1), 1);
    assert_eq!(obj.get(3), -1);
    obj.put(2, 1);
    assert_eq!(obj.get(2), 1);
    obj.remove(2);
    assert_eq!(obj.get(2), -1);
}
