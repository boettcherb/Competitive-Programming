#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc = 1;
    std::cin >> tc;
    while (tc--) {
        long long k, digits = 1, numNums = 9, start = 1;
        std::cin >> k;
        while (k > numNums * digits) {
            k -= numNums * digits;
            ++digits;
            numNums *= 10;
            start *= 10;
        }
        std::string num = std::to_string(start + (k - 1) / digits);
        std::cout << num[(k - 1) % digits] << '\n';
    }
}
