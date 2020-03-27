#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int papers = 0;
    for (char c : str) {
        if (c == 'p') {
            ++papers;
        }
    }
    std::cout << (str.length() / 2 - papers) << '\n';
    return 0;
}
