
class Solution {
public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> tin(n), tout(n), depth(n);
        vector<int> mask(n, 0);
        int timer = 0;

        // Iterative DFS to avoid stack overflow
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);

        vector<pair<int, int>> st;
        st.push_back({0, 0});
        parent[0] = 0;

        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = timer++;
                order.push_back(u);

                st.push_back({u, 1});

                for (int v : adj[u]) {
                    if (v == parent[u]) continue;

                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        auto bitMask = [&](char c) {
            return 1 << (c - 'a');
        };

        // Fenwick tree supporting range XOR updates
        // and point queries.
        vector<int> bit(n + 2, 0);

        auto updateBIT = [&](int idx, int val) {
            for (int i = idx + 1; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        };

        auto rangeXor = [&](int l, int r, int val) {
            updateBIT(l, val);
            if (r < n) updateBIT(r, val);
        };

        auto pointQuery = [&](int idx) {
            int res = 0;
            for (int i = idx + 1; i > 0; i -= i & -i) {
                res ^= bit[i];
            }
            return res;
        };

        // Initial root-to-node prefix masks.
        vector<int> base(n, 0);

        for (int u : order) {
            base[u] = bitMask(s[u]);

            if (u != 0) {
                base[u] ^= base[parent[u]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int change = bitMask(s[u]) ^ bitMask(c);

                // All root-prefix masks in u's subtree change.
                rangeXor(tin[u], tout[u], change);

                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int pu = base[u] ^ pointQuery(tin[u]);
                int pv = base[v] ^ pointQuery(tin[v]);

                // Include the LCA exactly once.
                int pathMask = pu ^ pv ^ bitMask(s[w]);

                // At most one character may have odd frequency.
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
