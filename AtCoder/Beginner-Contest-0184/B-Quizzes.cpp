#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, x;
    std::string s;
    std::cin >> n >> x >> s;
    for (char c : s) {
        x += (c == 'o');
        x -= (c == 'x');
        if (x < 0) ++x;
    }
    std::cout << x << '\n';
}
