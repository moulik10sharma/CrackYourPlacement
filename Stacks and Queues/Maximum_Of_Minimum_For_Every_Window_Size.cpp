class Solution {
public:
    vector<int> maxOfMin(int arr[], int n) {
        stack<int> s;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        vector<int> res(n);
        for (int i = 1; i <= n; i++) {
            res[i - 1] = ans[i];
        }
        return res;
    }
};