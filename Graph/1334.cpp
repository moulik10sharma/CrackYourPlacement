class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& edge : edges) {
            int v1 = edge[0], v2 = edge[1], dist = edge[2];
            adj[v1].emplace_back(v2, dist);
            adj[v2].emplace_back(v1, dist);
        }
        auto dijkstra = [&](int src) -> int {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
            unordered_set<int> visit;
            heap.emplace(0, src);

            while (!heap.empty()) {
                auto [dist, node] = heap.top();
                heap.pop();
                if (visit.find(node) != visit.end()) {
                    continue;
                }
                visit.insert(node);
                for (const auto& [nei, dist2] : adj[node]) {
                    int nei_dist = dist + dist2;
                    if (nei_dist <= distanceThreshold) {
                        heap.emplace(nei_dist, nei);
                    }
                }
            }
            return visit.size() - 1;
        };
        int res = -1, min_count = n;
        for (int src = 0; src < n; ++src) {
            int count = dijkstra(src);
            if (count <= min_count) {
                res = src;
                min_count = count;
            }
        }
        return res;
    }
};