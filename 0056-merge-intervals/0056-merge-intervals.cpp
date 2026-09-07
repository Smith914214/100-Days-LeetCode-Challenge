class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        // Handle empty input edge case
        if (intervals.empty()) {
            return {};
        }

        // 1. Sort intervals based on their start times
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> mergedIntervals;
        
        // Initialize with the first interval
        mergedIntervals.push_back(intervals[0]);

        // 2. Iterate through the remaining intervals
        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last interval added to our merged list
            std::vector<int>& lastMerged = mergedIntervals.back();
            
            // Check if the current interval overlaps with the last merged interval
            if (intervals[i][0] <= lastMerged[1]) {
                // Overlap found: merge them by updating the end time
                lastMerged[1] = std::max(lastMerged[1], intervals[i][1]);
            } else {
                // No overlap: add the current interval as a new entry
                mergedIntervals.push_back(intervals[i]);
            }
        }

        return mergedIntervals;
    }
};