// Problem: Check if Array Is Sorted and Rotated (LeetCode 1752)
// Approach:
// 1. Count the number of times the array decreases (nums[i] > nums[i+1]).
// 2. Use modulo to handle the circular comparison (nums[n-1] > nums[0]).
// 3. If the count of decreases is 0 → array is fully sorted, return true.
// 4. If the count of decreases is 1 → array is rotated sorted, return true.
// 5. If count > 1 → array is not sorted and rotated, return false.
// Time Complexity: O(n), traverse the array once.
// Space Complexity: O(1), only a counter variable used.

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();

        // Count number of times current element is greater than next (rotation check)
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // Array is sorted and rotated if count is 0 or 1
        if (count == 0 || count == 1) {
            return true;
        } else {
            return false;
        }
    }
};
