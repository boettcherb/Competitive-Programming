#include <iostream>

bool palindrome(int r, int g, int b, int w) {
    int numOdd = (r % 2) + (g % 2) + (b % 2) + (w % 2);
    return numOdd <= 1 && r >= 0 && g >= 0 && b >= 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int r, g, b, w;
        std::cin >> r >> g >> b >> w;
        if (palindrome(r, g, b, w) || palindrome(r - 1, g - 1, b - 1, w + 3)) {
            std::cout << "Yes" << '\n';
        } else {
            std::cout << "No" << '\n';
        }
    }
    return 0;
}
