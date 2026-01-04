// Problem: Missing Number (LeetCode 268)
// Approach:
// Use XOR operation to find the missing number.
// XOR of all numbers from 0 to n with all elements in the array
// will cancel out all existing numbers, leaving the missing one.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();

        // XOR of numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR of all elements in the array
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];
        }

        // XOR of both results gives the missing number
        return xor1 ^ xor2;
    }
};
