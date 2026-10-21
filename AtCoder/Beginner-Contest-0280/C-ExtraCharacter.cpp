#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;
    int res = 0, L = (int) t.length();
    for (int i = 0; i < L; ++i) {
        if (i == L - 1 || s[i] != t[i]) {
            res = i;
            break;
        }
    }
    std::cout << res + 1 << '\n';
}
