#include <iostream>
#include <string>
#include <algorithm>

const int N = 101;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, l;
    std::cin >> n >> l;
    std::string str[N];
    for (int i = 0; i < n; ++i) {
        std::cin >> str[i];
    }
    std::sort(str, str + n);
    for (int i = 0; i < n; ++i) {
        std::cout << str[i];
    }
    std::cout << '\n';
    return 0;
}
