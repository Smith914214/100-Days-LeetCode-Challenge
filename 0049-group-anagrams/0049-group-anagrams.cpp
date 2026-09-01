class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Map to group anagrams: {sorted_string -> list of original strings}
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        
        for (const std::string& str : strs) {
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end()); // Sort characters to create a uniform key
            anagramMap[sortedStr].push_back(str);          // Group the original string
        }
        
        // Collect all grouped vectors into the final result
        std::vector<std::vector<std::string>> result;
        result.reserve(anagramMap.size()); // Optimize memory allocation
        
        for (auto& pair : anagramMap) {
            result.push_back(std::move(pair.second));
        }
        
        return result;
    }
};