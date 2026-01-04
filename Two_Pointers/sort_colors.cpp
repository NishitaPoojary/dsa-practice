// Problem: Sort Colors (LeetCode 75)
// Approach:
// Use the Dutch National Flag algorithm with three pointers:
// 1. low → boundary for 0s
// 2. mid → current element
// 3. high → boundary for 2s
// Iterate through the array and swap elements to place 0s at the start, 2s at the end, 1s naturally in the middle.
// Time Complexity: O(n), each element is processed at most once.
// Space Complexity: O(1), in-place sorting without extra space.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]); // Move 0 to the front
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++; // 1 is in correct place
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]); // Move 2 to the end
                high--;
            }
        }
    }
};
