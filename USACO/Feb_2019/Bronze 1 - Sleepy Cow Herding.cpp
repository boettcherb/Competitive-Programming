#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int cows[3];
    std::cin >> cows[0] >> cows[1] >> cows[2];
    std::sort(cows, cows + 3);
    int min = 2;
    if (cows[1] - cows[0] == 1 && cows[2] - cows[1] == 1) {
        min = 0;
    }
    if (cows[1] - cows[0] == 2 || cows[2] - cows[1] == 2) {
        min = 1;
    }
    int max = std::max(cows[1] - cows[0], cows[2] - cows[1]) - 1;
    std::cout << min << '\n' << max << '\n';
    return 0;
}