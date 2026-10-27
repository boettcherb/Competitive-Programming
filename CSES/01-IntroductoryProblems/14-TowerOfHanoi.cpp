#include <iostream>

void move(int n, int from, int to) {
    if (n <= 0) return;
    move(n - 1, from, from ^ to);
    std::cout << from << ' ' << to << '\n';
    move(n - 1, from ^ to, to);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cout << ((1 << n) - 1) << '\n';
    move(n, 1, 3);
}
