// lowest common ancestor in a tree for every query of the form (u, v) offline (query in O(1)):
struct Value {
    int d = INT32_MAX, v = INT32_MAX;
 
    bool operator<(const Value& rhs) const& {
        return d < rhs.d;
    }
};

struct LCA {
    int n;
    vector<vector<int>> G;
    vector<Value> E; // depth, vertex
    vector<int> F;
    RMQ rmq;
 
    LCA(vector<vector<int>>& G) : n(G.size()), G(G), F(n, -1) {
        DFS(0, 0, 0);
        rmq = RMQ(E);
    }
 
    void DFS(int u, int p, int d) {
        if (F[u] == -1) F[u] = E.size();
        E.push_back({ d, u });
        for (auto& v : G[u]) {
            if (v == p) continue;
            E.push_back({ d, u });
            DFS(v, u, d + 1);
        }
    }
 
    int query(int p, int q) {
        auto [fp, fq] = minmax(F[p], F[q]);
        return rmq.query(fp, fq + 1).v;
    }
};


// lowest common ancestor in a tree for every query of the form (u, v) online:
struct LCA {
    int n, L;
    vector<vector<int>> G;

    vector<int> depth;
    vector<vector<int>> jumpp;

    LCA(int n) : n(n) {
        L = ceil(log2(n));
        G.resize(n), depth.resize(n);
        jumpp.resize(n, vector<int>(L + 1, -1));
    } 

    void DFS(int u, int p) {
        jumpp[u][0] = p;
        depth[u] = depth[p] + 1;
        for (int i = 1; i <= L; i++)
            jumpp[u][i] = jumpp[jumpp[u][i - 1]][i - 1];
        for (auto v : G[u])
            if (v != p)
                DFS(v, u);
    }

    int query(int u, int v) {
        if (u == v) return u;
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = L; i >= 0; --i)
            if (depth[jumpp[u][i]] >= depth[v])
                u = jumpp[u][i];
        if (u == v) return u;
        for (int i = L; i >= 0; --i) {
            if (jumpp[u][i] != jumpp[v][i]) {
                u = jumpp[u][i];
                v = jumpp[v][i];
            } 
        }
        return jumpp[u][0];
    }

    // przyłącz drzewo z wierzchołkiem u do tego z p
    void connect(int u, int p) {
        G[u].push_back(p);
        G[p].push_back(u);
        if (jumpp[p].back() == -1) 
            fill(jumpp[p].begin(), jumpp[p].end(), p);
        fill(jumpp[u].begin(), jumpp[u].end(), jumpp[p].back());
        DFS(u, p);
    }
};


// lowest common ancestor in a tree for every query of the form (u, v) offline (query in O(1) - alternative):
struct LCA {
    int n, L;
    vector<vector<int>>& G;
	
    int timer = 0;
    vector<pair<int, int>> tio; // time in, out
    vector<int> ftio; // first time in, out
    vector<vector<pair<int, int>>> jumpp; // depth, vertex
    vector<int> logs;
	
    // jeśli graf skierowany, to root może być jakikolwiek
    LCA(vector<vector<int>>& G, int root) : G(G), n(G.size()) {
        ftio.resize(n);
        DFS (root, root, 0);
        
        int m = tio.size();
        logs.resize(m);
        for (int i = 1; i < m; i++)
            logs[i] = logs[i - 1] + ((1 << (logs[i - 1] + 1)) <= i);
        
        L = logs.back() + 1;
        jumpp.resize(m, vector<pair<int, int>>(L + 1));
        for (int i = 0; i < m; i++) jumpp[i][0] = { tio[i].second, tio[i].first };
        for (int l = 1; l <= L; l++) {
            for (int i = 0; i < m; i++) {
                jumpp[i][l] = min(jumpp[i][l - 1], jumpp[min(i + (1 << (l - 1)), m - 1)][l - 1]);
            }
        }
    }
	
    void DFS(int v, int p, int t) {
        ftio[v] = tio.size();
        tio.push_back({ v, t });
        for (auto u : G[v]) {
            if (u != p) {
                DFS(u, v, t + 1);
                tio.push_back({ v, t });
            }
        }
    }
    
    int query(int u, int v) {
        pair<int, int> ff = minmax(ftio[u], ftio[v]);
        auto& [f1, f2] = ff;
        int l = logs[f2 - f1];
        auto [depth, anc] = min(jumpp[f1][l], jumpp[f2 - (1 << l)][l]);
        return anc;
    }
};


// lowest common ancestor in a tree for every query of the form (u, v) offline (query in O(log n)):
struct LCA {
    int n, L = 1;
    vector<vector<int>> G;
    vector<vector<int>> P;
    vector<int> D;
 
    LCA(vector<vector<int>>& G) : n(G.size()), G(G) {
        L = __lg(n) + 1;
        P = vector<vector<int>>(L, vector<int>(n));
        D = vector<int>(n);
        DFS(0);
 
        for (int l = 1; l < L; l++)
            for (int v = 0; v < n; v++)
                P[l][v] = P[l - 1][P[l - 1][v]];
    }
 
    void DFS(int u) {
        for (auto& v : G[u]) {
            if (v == P[0][u]) continue;
            P[0][v] = u;
            D[v] = D[u] + 1;
            DFS(v);
        }
    }
 
    int query(int a, int b) {
        if (D[a] > D[b]) swap(a, b);
 
        for (int l = L - 1; l >= 0; l--)
            if (D[a] <= D[P[l][b]])
                b = P[l][b];
 
        for (int l = L - 1; l >= 0; l--)
            if (P[l][a] != P[l][b])
                a = P[l][a], b = P[l][b];
 
        if (a != b) a = P[0][a];
        return a;
    }
};


// lowest common ancestor in a tree for every query of the form (u, v) offline (query in O(log n) - alternative):
struct LCA {
    int n, L;
    vector<vector<int>>& G;
	
    int timer = 0;
    vector<int> tin, tout;
    vector<vector<int>> jumpp;
	
    // jeśli graf skierowany, to root może być jakikolwiek
    LCA(vector<vector<int>>& G, int root) : G(G), n(G.size()) {
        L = ceil(log2(n));
        tin.resize(n), tout.resize(n);
        jumpp.resize(n, vector<int>(L + 1, root));
        DFS (root, root);
    }
	
    void DFS(int v, int p) {
        tin[v] = ++timer;
        jumpp[v][0] = p;
        for (int i = 1; i <= L; ++i)
            jumpp[v][i] = jumpp[jumpp[v][i - 1]][i - 1];
        for (auto u : G[v])
            if (u != p)
                DFS(u, v);
        tout[v] = ++timer;
    }
    
    bool isAnc(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    
    int query(int u, int v) {
        if (isAnc(u, v)) return u;
        if (isAnc(v, u)) return v;
        for (int i = L; i >= 0; --i)
            if (!isAnc(jumpp[u][i], v))
                u = jumpp[u][i];
        return jumpp[u][0];
    }
};

