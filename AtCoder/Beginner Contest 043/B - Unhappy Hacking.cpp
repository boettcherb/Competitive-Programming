#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str, res;
    std::cin >> str;
    int pos = 0;
    for (char c : str) {
        if (c == 'B') {
            if (pos > 0) {
                res[pos--] = 0;
            }
        } else {
            res[pos++] = c;
        }
    }
    for (int i = 0; i < pos; ++i) {
        std::cout << res[i];
    }
    std::cout << '\n';
    return 0;
}
