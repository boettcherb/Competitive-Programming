#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long k;
    std::cin >> k;
    std::map<long long, int> primeFactors;
    while (k % 2 == 0) {
        ++primeFactors[2];
        k /= 2;
    }
    for (long long i = 3; i * i <= k; i += 2) {
        while (k % i == 0) {
            ++primeFactors[i];
            k /= i;
        }
    }
    if (k > 1) ++primeFactors[k];
    long long res = 0;
    for (auto& [factor, factorCount] : primeFactors) {
        long long cur = 0;
        int count = 0;
        while (count < factorCount) {
            cur += factor;
            long long x = cur;
            while (x % factor == 0) {
                ++count;
                x /= factor;
            }
        }
        res = std::max(res, cur);
    }
    std::cout << res << '\n';
}
