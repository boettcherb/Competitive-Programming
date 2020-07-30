#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int candies[3];
    std::cin >> candies[0] >> candies[1] >> candies[2];
    std::sort(candies, candies + 3);
    std::cout << (candies[0] + candies[1] == candies[2] ? "Yes" : "No") << '\n';
    return 0;
}
