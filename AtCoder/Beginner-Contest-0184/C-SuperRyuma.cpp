#include <iostream>

bool oneMoveAway(long long a, long long b, long long c, long long d) {
    if (a + b == c + d) return true;
    if (a - b == c - d) return true;
    return std::abs(a - c) + std::abs(b - d) <= 3;
}

int solve(long long a, long long b, long long c, long long d) {
    if (a == c && b == d)
        return 0;
    if (oneMoveAway(a, b, c, d))
        return 1;
    if (std::abs(a - c) + std::abs(b - d) <= 6)
        return 2;
    long long n1 = a + b - c - d;
    long long n2 = a - b - c + d;
    if (oneMoveAway(a - n1 / 2, b - n1 / 2, c, d))
        return 2;
    if (oneMoveAway(a - n2 / 2, b + n2 / 2, c, d))
        return 2;
    return 3;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << solve(a, b, c, d) << '\n';
}
