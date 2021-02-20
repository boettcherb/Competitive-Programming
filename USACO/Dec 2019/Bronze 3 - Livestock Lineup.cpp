#include <iostream>
#include <string>
#include <vector>
#include <set>

const int N = 8;
const std::string cows[N] = { "Beatrice", "Belinda", "Bella",
    "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };

int getIndex(const std::string& name) {
    for (int i = 0; i < N; ++i) {
        if (name == cows[i]) {
            return i;
        }
    }
    throw "ERROR: getIndex(): Invalid Argument\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    std::vector<std::vector<int>> adj(N);
    bool used[N] = { false };
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string line[6];
        std::cin >> line[0] >> line[1] >> line[2];
        std::cin >> line[3] >> line[4] >> line[5];
        int u = getIndex(line[0]);
        int v = getIndex(line[5]);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int numPrinted = 0;
    while (numPrinted < N) {
        std::set<int> leaves;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && adj[i].size() < 2) {
                leaves.insert(i);
            }
        }
        int min = *leaves.begin();
        while (true) {
            std::cout << cows[min] << '\n';
            used[min] = true;
            ++numPrinted;
            int numAdj = adj[min].size();
            if (numAdj == 0 || (numAdj == 1 && min != *leaves.begin())) {
                break;
            }
            min = !used[adj[min][0]] ? adj[min][0] : adj[min][1];
        }
    }
    return 0;
}
