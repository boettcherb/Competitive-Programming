#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int res = 0;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] != str[i - 1]) {
            ++res;
        }
    }
    std::cout << res << '\n';
    return 0;
}
