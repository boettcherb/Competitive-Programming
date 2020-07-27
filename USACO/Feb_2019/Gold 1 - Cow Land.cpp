#include <iostream>
#include <vector>

struct Vertex {
    std::vector<int> adj;
    int parent;
    int depth;
    int segTreeIndex;
    int subtreeSize;
    int enjoymentValue;
};

struct SegmentTree {
    int top;
    std::vector<int> elements;
    std::vector<unsigned int> tree;

    void addElement(int index, int val) {
        if (elements.empty()) {
            top = index;
        }
        elements.push_back(val);
    }

    void build() {
        tree = std::vector<unsigned int>(4 * elements.size());
        build(1, 0, static_cast<int>(elements.size()) - 1);
    }

    void update(int index, int val) {
        update(1, 0, static_cast<int>(elements.size()) - 1, index, val);
    }

    unsigned int query(int left, int right) {
        return query(1, 0, static_cast<int>(elements.size()) - 1, left, right);
    }

    void build(int cur, int left, int right) {
        if (left == right) {
            tree[cur] = static_cast<unsigned int>(elements[left]);
        } else {
            int mid = (left + right) / 2;
            build(cur * 2, left, mid);
            build(cur * 2 + 1, mid + 1, right);
            tree[cur] = tree[cur * 2] ^ tree[cur * 2 + 1];
        }
    }

    void update(int cur, int left, int right, int goalIndex, int val) {
        if (left == right) {
            tree[cur] = val;
        } else {
            int mid = (left + right) / 2;
            if (goalIndex <= mid) {
                update(cur * 2, left, mid, goalIndex, val);
            } else {
                update(cur * 2 + 1, mid + 1, right, goalIndex, val);
            }
            tree[cur] = tree[cur * 2] ^ tree[cur * 2 + 1];
        }
    }

    unsigned int query(int cur, int curLeft, int curRight, int queryLeft, int queryRight) {
        if (curLeft >= queryLeft && curRight <= queryRight) {
            return tree[cur];
        }
        if (queryLeft > curRight || queryRight < curLeft) {
            return 0;
        }
        int mid = (curLeft + curRight) / 2;
        return query(cur * 2, curLeft, mid, queryLeft, queryRight)
            ^ query(cur * 2 + 1, mid + 1, curRight, queryLeft, queryRight);
    }
};

const int N = 1e5 + 10;
Vertex vertices[N];
SegmentTree segTrees[N];

// fill in the depth, subtree size, and parent for every vertex
void dfs(int cur, int parent) {
    vertices[cur].parent = parent;
    vertices[cur].subtreeSize = 1;
    for (int adj : vertices[cur].adj) {
        if (adj != parent) {
            vertices[adj].depth = vertices[cur].depth + 1;
            dfs(adj, cur);
            vertices[cur].subtreeSize += vertices[adj].subtreeSize;
        }
    }
}

// add every vertex to a segTree and set the segTree index for every vertex
void hld(int cur, int parent, int& segTreeIndex) {
    vertices[cur].segTreeIndex = segTreeIndex;
    segTrees[segTreeIndex].addElement(cur, vertices[cur].enjoymentValue);
    int maxSubtreeChild = -1;
    int maxSubtree = -1;
    for (int adj : vertices[cur].adj) {
        if (adj != parent) {
            if (vertices[adj].subtreeSize > maxSubtree) {
                maxSubtree = vertices[adj].subtreeSize;
                maxSubtreeChild = adj;
            }
        }
    }
    if (maxSubtreeChild != -1) {
        hld(maxSubtreeChild, cur, segTreeIndex);
        for (int adj : vertices[cur].adj) {
            if (adj != parent && adj != maxSubtreeChild) {
                hld(adj, cur, ++segTreeIndex);
            }
        }
    }
}

unsigned int query(int u, int v) {
    unsigned int res = 0;
    while (vertices[u].segTreeIndex != vertices[v].segTreeIndex) {
        int uTopDepth = vertices[segTrees[vertices[u].segTreeIndex].top].depth;
        int vTopDepth = vertices[segTrees[vertices[v].segTreeIndex].top].depth;
        if (uTopDepth > vTopDepth) {
            res ^= segTrees[vertices[u].segTreeIndex].query(0, vertices[u].depth - uTopDepth);
            u = vertices[segTrees[vertices[u].segTreeIndex].top].parent;
        } else {
            res ^= segTrees[vertices[v].segTreeIndex].query(0, vertices[v].depth - vTopDepth);
            v = vertices[segTrees[vertices[v].segTreeIndex].top].parent;
        }
    }
    int topDepth = vertices[segTrees[vertices[u].segTreeIndex].top].depth;
    if (vertices[u].depth < vertices[v].depth) {
        return res ^ segTrees[vertices[u].segTreeIndex].query(vertices[u].depth - topDepth, vertices[v].depth - topDepth);
    } else {
        return res ^ segTrees[vertices[u].segTreeIndex].query(vertices[v].depth - topDepth, vertices[u].depth - topDepth);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);

    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        std::cin >> vertices[i].enjoymentValue;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        vertices[--u].adj.push_back(--v);
        vertices[v].adj.push_back(u);
    }
    dfs(0, -1);
    int segTreeIndex = 0;
    hld(0, -1, segTreeIndex);
    for (int i = 0; i <= segTreeIndex; ++i) {
        segTrees[i].build();
    }
    for (int i = 0; i < q; ++i) {
        int type, a, b;
        std::cin >> type >> a >> b;
        if (type == 1) {
            int topDepth = vertices[segTrees[vertices[--a].segTreeIndex].top].depth;
            segTrees[vertices[a].segTreeIndex].update(vertices[a].depth - topDepth, b);
        } else {
            std::cout << query(--a, --b) << std::endl;
        }
    }
    return 0;
}
