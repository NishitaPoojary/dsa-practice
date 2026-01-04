// Problem: Merge Sorted Array (LeetCode 88)
// Approach:
// Use two pointers starting from the end of nums1 and nums2.
// Compare elements and place the larger one at the end of nums1.
// This avoids overwriting existing elements in nums1.
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // Pointer for nums1
        int j = n - 1;          // Pointer for nums2
        int r = m + n - 1;      // Pointer for merged array position

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[r] = nums1[i];
                i--;
            } else {
                nums1[r] = nums2[j];
                j--;
            }
            r--;
        }
    }
};
