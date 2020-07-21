#include <iostream>
#include <string>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::string str;
    std::cin >> n >> str;
    int colors[N] = { 0 }, color = 0, numColored = 0;
    while (numColored < n) {
        ++color;
        int largestLetter = 'a';
        for (int j = 0; j < n; ++j) {
            if (!colors[j] && str[j] >= largestLetter) {
                ++numColored;
                colors[j] = color;
                largestLetter = str[j];
            }
        }
    }
    std::cout << color << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << colors[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
