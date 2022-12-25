// Segment Tree (update on segment, query on segment +/+, +/min, min/min)
// time complexity: O(n * log(n)), query O(log (n)), space: O(n * log(n))

struct Value { 
	int v = 0;
};
 
Value operator+ (const Value& lhs, const Value& rhs) {
    return { max(lhs.v, rhs.v) }; 
}
 
struct Modifier {
    int m = 0;
};
 
Modifier operator* (const Modifier& lhs, const Modifier& rhs) {
    return { lhs.m + rhs.m };
}
 
Value operator* (const Value& lhs, const Modifier& rhs) {
    return { lhs.v + rhs.m };
}
 
template <typename Value>
struct Tree {
    struct Node {
        Value value;
        Modifier modifier;
        operator Value() {
            return value * modifier;
        }
    };
 
    int L = 1;
    vector<Node> T;
 
    Tree(const int n) {
        while (L <= n) L *= 2;
        T.resize(2 * L);
		for (int i = L - 1; i > 0; i--)
            T[i].value = T[2 * i] + T[2 * i + 1];
    }
	
	Tree(const vector<Value>& V) {
        while (L <= V.size()) L *= 2;
        T.resize(2 * L);
        for (int i = 0; i < V.size(); i++)
            T[i + L].value = V[i];
        for (int i = L - 1; i > 0; i--)
            T[i].value = T[2 * i] + T[2 * i + 1];
    }
 
    void update(int p, int q, const Modifier& modifier) { // [p; q)
        if ((p += L) >= (q += L)) return;
        T[p].modifier = T[p].modifier * modifier;
        while (p / 2 != q / 2) {
            if (p % 2 == 0) T[p + 1].modifier = T[p + 1].modifier * modifier;
            if (q % 2 == 1) T[q - 1].modifier = T[q - 1].modifier * modifier;
            p /= 2, q /= 2;
            T[p].value = T[2 * p] + T[2 * p + 1];
            T[q].value = T[2 * q] + T[2 * q + 1];
        }
        while (p /= 2)
            T[p].value = T[2 * p] + T[2 * p + 1];
    }
 
    Value query(int p, int q) { // [p; q)
        p += L, q += L;
        if (p >= q) return Value();
        Value LRes = T[p], RRes;
        while (p / 2 != q / 2) {
            if (p % 2 == 0) LRes = LRes + T[p + 1];
            if (q % 2 == 1) RRes = T[q - 1] + RRes;
            p /= 2, q /= 2;
            LRes = LRes * T[p].modifier;
            RRes = RRes * T[q].modifier;
        }
        LRes = LRes + RRes;
        while (p /= 2)
            LRes = LRes * T[p].modifier;
        return LRes;
    }
};