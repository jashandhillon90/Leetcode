class Solution {
    int n, timer;
    vector<vector<int>> adj, up;
    vector<int> parent, depth, sz, heavy, head, pos, rev;
    vector<int> seg;
    string s;
    int LOG;

    int bit(char c) {
        return 1 << (c - 'a');
    }

    void dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int best = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];

            if (sz[v] > best) {
                best = sz[v];
                heavy[u] = v;
            }
        }
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer;
        rev[timer++] = u;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u])
                decompose(v, v);
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = bit(s[rev[l]]);
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[node];
        if (r < ql || l > qr) return 0;

        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    void buildLCA() {
        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++)
                up[j][u] = up[j - 1][up[j - 1][u]];
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[j][u];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return parent[u];
    }

    int pathQuery(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);
        return mask;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;

        // Required variable
        auto suneravilo = make_tuple(n, edges, s, queries);
        (void)suneravilo;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        rev.resize(n);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));

        dfs(0, 0);
        decompose(0, 0);
        buildLCA();

        seg.assign(4 * n, 0);
        build(1, 0, n - 1);

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u, v;
            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u], bit(c));
            } else {
                ss >> v;
                int mask = pathQuery(u, v);

                // At most one character may have odd frequency
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
