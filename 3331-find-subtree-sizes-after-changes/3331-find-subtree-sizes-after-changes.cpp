class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> newParent(n);
        vector<int> last(26, -1);
        vector<int> order;

        stack<tuple<int, bool, int>> st;
        st.push({0, false, -1});

        while (!st.empty()) {
            auto [u, exit, old] = st.top();
            st.pop();

            int ch = s[u] - 'a';

            if (!exit) {
                newParent[u] = (last[ch] == -1) ? parent[u] : last[ch];

                old = last[ch];
                last[ch] = u;

                order.push_back(u);
                st.push({u, true, old});

                for (int v : tree[u]) {
                    st.push({v, false, -1});
                }
            } else {
                last[ch] = old;
            }
        }

        vector<int> ans(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (newParent[u] != -1) {
                ans[newParent[u]] += ans[u];
            }
        }

        return ans;
    }
};