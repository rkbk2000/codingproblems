// Runtime: 4 ms, faster than 100.00% of Rust online submissions for Maximum Product Difference Between Two Pairs.
// Memory Usage: 2.1 MB, less than 100.00% of Rust online submissions for Maximum Product Difference Between Two Pairs.

impl Solution {
    pub fn max_product_difference(nums: Vec<i32>) -> i32 {
        let mut a = nums;
        a.sort();

        return a[a.len() - 1] * a[a.len() - 2] - a[0] * a[1];
    }
}

// Runtime: 4 ms, faster than 100.00% of Rust online submissions for Maximum Product Difference Between Two Pairs.
// Memory Usage: 2.1 MB, less than 100.00% of Rust online submissions for Maximum Product Difference Between Two Pairs.

impl Solution1 {
    pub fn max_product_difference(nums: Vec<i32>) -> i32 {
        let mut a = nums;
        a.sort_unstable();

        return a[a.len() - 1] * a[a.len() - 2] - a[0] * a[1];
    }
}
