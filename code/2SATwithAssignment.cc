// Solves Two-Sat supposing we are given :
//   - a vector of size N corresponding to the assignation returned
//   - a graph of implication on 2N vertices, such that 2k corresponds
//   to the assignment 'true' for kth variable and 2k+1 to false.
// Also returns whether or not it's satisfiable.

void dfs1(vector<vector<int>> &g, vector<bool> &used, vector<int> &order, int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(g, used, order, u);
    }
    order.push_back(v);
}

void dfs2(vector<vector<int>> &gt, vector<int> &comp, int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(gt, comp, u, cl);
    }
}

vector<vector<int>> transpose(vector<vector<int>> &g, int n) {
    vector<vector<int>> gt(n);
    for(int i = 0; i < n; ++i) for(int u : g[i]) gt[u].push_back(i);
    return gt;
}

bool solve_2SAT(vector<vector<int>> &g, vector<bool> &assignment) {
    int n = g.size();
    vector<vector<int>> gt = transpose(g, n);
    vector<bool> used(n, false);
    vector<int> order, comp(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(g, used, order, i);
    }

    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(gt, comp, v, j++);
    }

    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}
