/*
 * @lc app=leetcode id=70 lang=rust
 *
 * [70] Climbing Stairs
 */

struct Solution;

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut cache = HashMap::<i32, i32>::new();
        cache.insert(0, 1);
        cache.insert(1, 1);
        Solution::fibonacchi(&mut cache, n)
    }

    fn fibonacchi(cache: &mut HashMap<i32, i32>, n: i32) -> i32 {
        if cache.contains_key(&n) {
            return *cache.get(&n).unwrap();
        }
        if !cache.contains_key(&(n - 1)) {
            Solution::fibonacchi(cache, n - 1);
        }
        cache.insert(
            n,
            *cache.get(&(n - 2)).unwrap() + *cache.get(&(n - 1)).unwrap(),
        );
        return *cache.get(&n).unwrap();
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::climb_stairs(1), 1);
}

#[test]
fn test2() {
    assert_eq!(Solution::climb_stairs(2), 2);
}

#[test]
fn test3() {
    assert_eq!(Solution::climb_stairs(3), 3);
}

#[test]
fn test4() {
    assert_eq!(Solution::climb_stairs(4), 5);
}

#[test]
fn test5() {
    assert_eq!(Solution::climb_stairs(5), 8);
}
