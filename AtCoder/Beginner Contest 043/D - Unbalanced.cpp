#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int l = -1, r = -1;
    for (int i = 2; i < str.length(); ++i) {
        if (str[i] == str[i - 1] || str[i] == str[i - 2]) {
            l = i - 1;
            r = i + 1;
            break;
        }
    }
    if (str[0] == str[1]) {
        l = 1;
        r = 2;
    }
    std::cout << l << ' ' << r << '\n';
    return 0;
}
