class Solution 
{
    public:
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    int pos[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    bool vis[N][N];
    memset(vis, false, sizeof(vis));
    int startX = KnightPos[0] - 1;
    int startY = KnightPos[1] - 1;
    int targetX = TargetPos[0] - 1;
    int targetY = TargetPos[1] - 1;
    vis[startX][startY] = true;
    queue<pair<int, int>> q;
    q.push({startX, startY});
    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if (x == targetX && y == targetY)
                return steps;
            for (int k = 0; k < 8; k++) {
                int a = x + pos[k][0], b = y + pos[k][1];
                if (a >= 0 && a < N && b >= 0 && b < N && !vis[a][b]) {
                    q.push({a, b});
                    vis[a][b] = true;
                }
            }
        }
        steps++;
    }
    return -1;
    }
};