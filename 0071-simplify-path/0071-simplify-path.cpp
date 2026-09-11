class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string token;
        
        // Split the string by '/'
        while (std::getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }
        
        // Reconstruct the simplified canonical path
        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }
        
        // If the stack was empty, return the root directory "/"
        return result.empty() ? "/" : result;
    }
};