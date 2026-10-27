#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;
    std::vector<int> s1, s2;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        std::cout << "NO" << '\n';
        return 0;
    }
    sum /= 2;
    for (int i = n; i > 0; --i) {
        if (sum >= i) {
            s1.push_back(i);
            sum -= i;
        } else {
            s2.push_back(i);
        }
    }
    std::cout << "YES" << '\n' << s1.size() << '\n';
    for (int x : s1) {
        std::cout << x << ' ';
    }
    std::cout << '\n' << s2.size() << '\n';
    for (int x : s2) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
