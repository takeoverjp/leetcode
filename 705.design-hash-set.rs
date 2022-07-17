/*
 * @lc app=leetcode id=705 lang=rust
 *
 * [705] Design HashSet
 */

// @lc code=start
use std::collections::HashSet;

struct MyHashSet {
    set: HashSet<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashSet {
    fn new() -> Self {
        MyHashSet {
            set: HashSet::<i32>::new(),
        }
    }

    fn add(&mut self, key: i32) {
        self.set.insert(key);
    }

    fn remove(&mut self, key: i32) {
        self.set.remove(&key);
    }

    fn contains(&self, key: i32) -> bool {
        self.set.contains(&key)
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * let obj = MyHashSet::new();
 * obj.add(key);
 * obj.remove(key);
 * let ret_3: bool = obj.contains(key);
 */
// @lc code=end

#[test]
fn test1() {
    let mut obj = MyHashSet::new();
    obj.add(1);
    obj.add(2);
    assert!(obj.contains(1));
    assert!(!obj.contains(3));
    obj.add(2);
    assert!(obj.contains(2));
    obj.remove(2);
    assert!(!obj.contains(2));
}
