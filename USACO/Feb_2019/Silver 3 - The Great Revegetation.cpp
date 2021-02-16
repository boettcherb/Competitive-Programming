#include <iostream>
#include <vector>

struct Vertex {
    std::vector<std::pair<int, bool>> adj;
    int seedType = -1;
    bool visited = false;
};

std::vector<Vertex> graph;

void floodFill(int cur) {
    graph[cur].visited = true;
    for (std::pair<int, bool>& e : graph[cur].adj) {
        int adjVertex = e.first;
        bool same = e.second;
        int curSeed = graph[cur].seedType;
        int adjSeed = graph[adjVertex].seedType;
        if (adjSeed != -1 && same != (curSeed == adjSeed)) {
            std::cout << "0\n";
            exit(0);
        }
        if (!graph[adjVertex].visited) {
            graph[adjVertex].seedType = same ? curSeed : curSeed ^ 1;
            floodFill(adjVertex);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    graph = std::vector<Vertex>(n);
    for (int i = 0; i < m; ++i) {
        char seed;
        int u, v;
        std::cin >> seed >> u >> v;
        graph[--u].adj.emplace_back(--v, seed == 'S');
        graph[v].adj.emplace_back(u, seed == 'S');
    }
    int numComponents = 0;
    for (int i = 0; i < n; ++i) {
        if (!graph[i].visited) {
            ++numComponents;
            graph[i].seedType = 0;
            floodFill(i);
        }
    }
    std::cout << '1';
    for (int i = 0; i < numComponents; ++i) {
        std::cout << '0';
    }
    std::cout << '\n';
    return 0;
}
