class Solution {
public:
    vector<string> res; 
    string current;       
    void backtrack(int openN, int closedN, int n) {
        if (openN == closedN && openN == n) {
            res.push_back(current);
            return;
        }
        if (openN < n) {
            current.push_back('(');
            backtrack(openN + 1, closedN, n);
            current.pop_back();
        }
        if (closedN < openN) {
            current.push_back(')');
            backtrack(openN, closedN + 1, n);
            current.pop_back();
        }
    }    
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;
    }
};