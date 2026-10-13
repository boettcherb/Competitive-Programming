#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    long long k;
    std::cin >> s >> k;
    int index = 0;
    while (index < (int) s.length() && s[index] == '1') {
        ++index;
    }
    std::cout << (k <= index ? '1' : s[index]) << '\n';
}
