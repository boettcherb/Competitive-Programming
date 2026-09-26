#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
#endif

    int n, k;
    std::cin >> n >> k;
    int curChars = 0;
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        int len = (int) word.length();
        if (curChars + len <= k) {
            std::cout << (curChars > 0 ? " " : "") << word;
            curChars += len;
        } else {
            std::cout << '\n' << word;
            curChars = len;
        }
    }
    std::cout << '\n';
}
