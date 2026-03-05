#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int mx = 0;
        for (auto& row : grid) {
            mx = max(mx, ranges::max(row));
        }

        vector<int> suf_min_f(mx + 2, INT_MAX);
        vector<int> min_f(mx + 1);
        vector<int> f(n + 1);

        for (int t = 0; t <= k; t++) {
            ranges::fill(min_f, INT_MAX);

            // 64. 最小路径和（空间优化写法）
            ranges::fill(f, INT_MAX / 2);
            f[1] = -grid[0][0]; // 起点的成本不算
            for (auto& row : grid) {
                for (int j = 0; j < n; j++) {
                    int x = row[j];
                    f[j + 1] = min(min(f[j], f[j + 1]) + x, suf_min_f[x]);
                    min_f[x] = min(min_f[x], f[j + 1]);
                }
            }

            // 计算 min_f 的后缀最小值
            for (int i = mx; i >= 0; i--) {
                suf_min_f[i] = min(suf_min_f[i + 1], min_f[i]);
            }
        }

        return f[n];
    }
};