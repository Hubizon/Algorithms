struct FindUnion {
	int n = 0;
	int componentsNum;
	vector<int> sizes, P;

	FindUnion(int n) {
		this->n = n;
		componentsNum = n;
		sizes.resize(n, 1);
		P.resize(n);
		for (int i = 0; i < n; i++) P[i] = i;
	}

	int find(int v) {
		if (P[v] != v) P[v] = find(P[v]);
		return P[v];
	}

	int find2(int v) {
		int root = v;
		while (root != P[root]) root = P[root];
		while (v != root) {
			int next = P[v];
			P[v] = root;
			v = next;
		}
		return root;
	}

	void unify(int v, int u) {
		int root1 = find(v), root2 = find(u);
		if (root1 == root2) return;
		if (sizes[root1] >= sizes[root2]) {
			sizes[root1] += sizes[root2];
			P[root2] = root1;
		}
		else {
			sizes[root2] += sizes[root1];
			P[root1] = root2;
		}
		componentsNum--;
	}

	bool connected(int v, int u) {
		return find(v) == find(u);
	}

	int componentSize(int v) {
		return sizes[find(v)];
	}
};