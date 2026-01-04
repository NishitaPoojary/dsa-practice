// Problem: Search Insert Position (LeetCode 35)
// Approach:
// 1. Use binary search to find the target in a sorted array.
// 2. Maintain two pointers: left and right.
// 3. If target is found at mid, return mid.
// 4. If target is greater than nums[mid], search right half (left = mid + 1).
// 5. If target is smaller, search left half (right = mid - 1).
// 6. If target is not found, left will be the correct insertion position.
// Time Complexity: O(log n), binary search halves the search space each iteration.
// Space Complexity: O(1), only a few variables used.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        // Standard binary search
        while (left <= right) {
            int mid = (left + right) / 2; // Could use left + (right-left)/2 to avoid overflow

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Search right half
            } else {
                right = mid - 1; // Search left half
            }
        }

        // Target not found, left is the correct insertion index
        return left;
    }
};
