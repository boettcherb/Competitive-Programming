/*

CSES: Introductory Problems: Permutations

Given an integer n, construct a permutation of the numbers 1..n where no two
adjacent elements have a different of 1. If no such permutation exists, print
"NO SOLUTION". If there are multiple possible solutions, print any of them.

Constraints:
    1 <= n <= 1,000,000

Example Input:
5

Example Output:
4 2 5 3 1

The only values of n where no solution exists are 2 and 3. For every other
value of n we can print all the even numbers, then all the odd numbers.

*/

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "1\n";
    } else if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION\n";
    } else {
        std::cout << 2;
        for (int i = 4; i <= n; i += 2) {
            std::cout << ' ' << i;
        }
        for (int i = 1; i <= n; i += 2) {
            std::cout << ' ' << i;
        }
    }
}
