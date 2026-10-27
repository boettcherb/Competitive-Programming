#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;
    int cur = 1, res = 1;
    for (int i = 1; i < (int) str.length(); ++i) {
        if (str[i] == str[i - 1])
            ++cur;
        else
            cur = 1;
        res = std::max(res, cur);
    }
    std::cout << res << '\n';
}
