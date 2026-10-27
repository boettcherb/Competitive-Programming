#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> ways(n + 1);
    for (int i = 2; i <= n; ++i) {
        long long prevSquares = (i - 1) * (i - 1);
        long long newSquares = 2 * i - 1;
        ways[i] = ways[i - 1] + newSquares * (newSquares - 1) / 2 - 2;
        ways[i] += (prevSquares - 2) * 5;
        ways[i] += (prevSquares - 3) * 4;
        ways[i] += (prevSquares - 4) * (i - 5) * 2;
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ways[i] << '\n';
    }
}
