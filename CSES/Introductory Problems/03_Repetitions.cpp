#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int cur = 1, max = 0;
    for (int i = 1; i < (int) str.length(); ++i) {
        if (str[i] == str[i - 1]) {
            ++cur;
        } else {
            max = std::max(max, cur);
            cur = 1;
        }
    }
    max = std::max(max, cur);
    std::cout << max << '\n';
    return 0;
}
