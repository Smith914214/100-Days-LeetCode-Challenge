class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // Step 1: Add all intervals that end before the new interval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // Step 2: Merge all overlapping intervals with the new interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval); // Insert the merged interval
        
        // Step 3: Add all remaining intervals that start after the new interval ends
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};