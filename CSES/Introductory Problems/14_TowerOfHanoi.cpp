#include <iostream>

const int N = 17;

void move(int num, int from, int to) {
    int other = from + to == 3 ? 3 : from + to == 4 ? 2 : 1;
    if (num == 1) {
        std::cout << from << ' ' << to << '\n';
    } else if (num == 2) {
        std::cout << from << ' ' << other << '\n';
        std::cout << from << ' ' << to << '\n';
        std::cout << other << ' ' << to << '\n';
    } else {
        move(num - 1, from, other);
        std::cout << from << ' ' << to << '\n';
        move(num - 1, other, to);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int moves[N] = { 0, 1 };
    for (int i = 2; i < N; ++i) {
        moves[i] = 2 * moves[i - 1] + 1;
    }
    int n;
    std::cin >> n;
    std::cout << moves[n] << '\n';
    move(n, 1, 3);
    return 0;
}
