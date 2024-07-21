class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string cur;
        stringstream ss(path);
        string segment;
        while (getline(ss, segment, '/')) {
            if (segment == "" || segment == ".") {
                continue;
            } else if (segment == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(segment);
            }
        }
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];
            if (i != stack.size() - 1) {
                result += "/";
            }
        }
        return result;
    }
};