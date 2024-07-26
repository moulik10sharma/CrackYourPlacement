class Solution {
private:
    void bfs(int sr, int sc, vector<vector<int>>& image, int newColor, int originalColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == originalColor) {
                    image[nrow][ncol] = newColor;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            bfs(sr, sc, image, color, originalColor);
        }
        return image;
    }
};