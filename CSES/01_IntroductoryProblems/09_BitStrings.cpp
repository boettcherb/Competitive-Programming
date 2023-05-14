/*

Given an integer n, calculate the number of bit strings of length n. Print the
answer modulo 10^9 + 7.

The answer to this is just 2^n. Set up a variable res = 1 and perform res *= 2
n times. At each step, make sure to also perform res %= 10^9 + 7 to avoid
integer overflow.

Constraints:
 - 1 <= n <= 1,000,000

Example Input:
3

Example Output:
8

*/

#include <iostream>

const int MOD = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res = (res * 2) % MOD;
    }
    std::cout << res << '\n';
}
