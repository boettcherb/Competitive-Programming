#include <iostream>
#include <list>

long long pow10(int pow) {
    if (pow == 0) {
        return 0;
    }
    long long res = 1;
    for (int i = 0; i < pow; ++i) {
        res *= 10;
    }
    return res;
}

int findDigit(long long num, long long offset) {
    std::list<int> digits;
    while (num) {
        long long digit = (int) (num % 10);
        digits.push_front(digit);
        num /= 10;
    }
    for (int i = 0; i < offset; ++i) {
        digits.pop_front();
    }
    return digits.front();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long numCount[20] = { 0, 9 };
    for (int i = 2; i < 19; ++i) {
        numCount[i] = 10 * numCount[i - 1];
    }
    int q;
    std::cin >> q;
    while (q--) {
        long long x;
        std::cin >> x;
        for (int i = 1; i < 19; ++i) {
            long long digitsI = numCount[i] * i;
            if (x > digitsI) {
                x -= digitsI;
            } else {
                if (i > 1) {
                    --x;
                }
                long long num = pow10(i - 1) + x / i;
                long long offset = x % i;
                std::cout << findDigit(num, offset) << '\n';
                break;
            }
        }
    }
    return 0;
}
