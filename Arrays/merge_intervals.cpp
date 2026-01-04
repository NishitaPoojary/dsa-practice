// Problem: Merge Intervals (LeetCode 56)
// Approach:
// 1. Sort the intervals based on the start time.
// 2. Use two pointers (i and j) to check consecutive intervals for overlap.
// 3. If intervals overlap, merge them by updating the start and end of intervals[j].
// 4. If no overlap, push intervals[i] to the result vector.
// 5. Finally, push the last interval after the loop.
// Time Complexity: O(n log n) due to sorting.
// Space Complexity: O(n) for the merged intervals vector.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // Sort intervals by start time
        
        int i = 0, j = i + 1;
        vector<vector<int>> merged;

        // Iterate through intervals with two pointers
        while (i <= intervals.size() - 2 && j <= intervals.size() - 1) {
            if (intervals[i][1] >= intervals[j][0]) {
                // Merge overlapping intervals by updating intervals[j]
                intervals[j][0] = min(intervals[i][0], intervals[j][0]);
                intervals[j][1] = max(intervals[i][1], intervals[j][1]);
            } else {
                // No overlap, add intervals[i] to merged
                merged.push_back(intervals[i]);
            }
            i++;
            j++;
        }

        // Push the last interval
        merged.push_back(intervals.back());

        return merged;
    }
};
