// Problem: Squares of a Sorted Array (LeetCode 977)
// Approach:
// 1. Use two pointers (i at start, j at end) to compare absolute values.
// 2. The larger absolute value squared goes at the end of the result.
// 3. Push squares into a result vector in reverse order.
// 4. Reverse the result at the end to get ascending order.
// Time Complexity: O(n), each element is processed once.
// Space Complexity: O(n), for the result vector.

#include <algorithm>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> result;

        // Compare absolute values from both ends
        while (i <= j) {
            if (abs(nums[i]) < abs(nums[j])) {
                result.push_back(nums[j] * nums[j]);
                j--;
            } else {
                result.push_back(nums[i] * nums[i]);
                i++;
            }
        }

        // Reverse to get ascending order
        reverse(result.begin(), result.end());
        return result;
    }
};
