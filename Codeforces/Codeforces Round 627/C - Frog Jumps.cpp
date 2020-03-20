#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        std::string str;
        std::cin >> str;
        int res = 1;
        for (int i = 0; i < str.length(); ++i) {
            int numL = 0;
            while (i + numL < str.length() && str[i + numL] == 'L') {
                ++numL;
            }
            i += numL;
            res = res > numL + 1 ? res : numL + 1;
        }
        std::cout << res << '\n';
    }
    return 0;
}
