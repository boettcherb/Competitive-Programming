#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);

    const int arr[8] = { 1, 2, 4, 7, 8, 11, 13, 14 };

    long long n;
    std::cin >> n;
    --n;
    std::cout << (n / 8 * 15 + arr[(int) (n % 8)]) << '\n';
    return 0;
}
