/*

Given an integer n, find the number of trailing zeros of n!.

A trailing zero occurs when a number has both a 2 and a 5 as a factor (because
2 * 5 == 10). To find out how many trailing zeros a number has, we find out how
many 2's and 5's it has in its prime factorization and take the minimum. A
number n! will always have more 2's than 5's, so we just need to count the 5's.
n / 5 is the number of factors of n! that are divisible by 5. n / 25 is the
number of factors of n! that are divisible by 25. Note that 25 is made up of
two 5's, but we've already counted one of them in the previous step when we do
n / 5. Keep doing this for every power of 5 <= n and sum up the results.

Constraints:
 - 1 <= n <= 1,000,000,000

Example Input:
20

Example Output:
4

*/

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    long long five = 0;
    for (long long cur5 = 5; cur5 <= n; cur5 *= 5) {
        five += n / cur5;
    }
    std::cout << five << '\n';
}
