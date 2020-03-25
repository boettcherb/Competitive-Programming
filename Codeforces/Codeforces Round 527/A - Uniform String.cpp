#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, k;
        std::cin >> n >> k;
        std::string str;
        for (int i = 0; i < n; ++i) {
            str += (char) (i % k + 'a');
        }
        std::cout << str << '\n';
    }
    return 0;
}
