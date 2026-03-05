#include <vector>
#include <string>
using namespace std;
struct Node {
    Node* son[26]{};
    int sid = -1; // 字符串的编号
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        Node* root = new Node();
        int sid = 0;
        auto put = [&](string& s) -> int {
            Node* o = root;
            for (char b : s) {
                int i = b - 'a';
                if (o->son[i] == nullptr) {
                    o->son[i] = new Node();
                }
                o = o->son[i];
            }
            if (o->sid < 0) {
                o->sid = sid++;
            }
            return o->sid;
        };

        // 初始化距离矩阵
        int m = cost.size();
        vector dis(m * 2, vector<int>(m * 2, INT_MAX / 2));
        for (int i = 0; i < m * 2; i++) {
            dis[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int x = put(original[i]);
            int y = put(changed[i]);
            dis[x][y] = min(dis[x][y], cost[i]);
        }

        // Floyd 求任意两点最短路
        for (int k = 0; k < sid; k++) {
            for (int i = 0; i < sid; i++) {
                if (dis[i][k] == INT_MAX / 2) { // 加上这句话，巨大优化！
                    continue;
                }
                for (int j = 0; j < sid; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int n = source.size();
        vector<long long> memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) -> long long {
            if (i >= n) {
                return 0;
            }
            auto& res = memo[i]; // 注意这里是引用
            if (res != -1) {
                return res;
            }
            res = LONG_LONG_MAX / 2;
            if (source[i] == target[i]) {
                res = dfs(i + 1); // 不修改 source[i]
            }
            Node* p = root;
            Node* q = root;
            for (int j = i; j < n; j++) {
                p = p->son[source[j] - 'a'];
                q = q->son[target[j] - 'a'];
                if (p == nullptr || q == nullptr) {
                    break;
                }
                if (p->sid < 0 || q->sid < 0) {
                    continue;
                }
                // 修改从 i 到 j 的这一段
                int d = dis[p->sid][q->sid];
                if (d < INT_MAX / 2) {
                    res = min(res, dis[p->sid][q->sid] + dfs(j + 1));
                }
            }
            return res;
        };
        long long ans = dfs(0);
        return ans < LONG_LONG_MAX / 2 ? ans : -1;
    }
};