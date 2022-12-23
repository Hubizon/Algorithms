// LCA (lowest common ancestor in a tree offline)
// time complexity: O(n * log(n)), query O(1), space: O(n * log(n))

struct Value {
    int d = INT32_MAX, v = INT32_MAX;
 
    bool operator<(const Value& rhs) const& {
        return d < rhs.d;
    }
};

template<typename Value>
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