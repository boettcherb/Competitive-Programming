#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;
    std::sort(str.begin(), str.end());
    std::vector<std::string> strs = { str };
    while (std::next_permutation(str.begin(), str.end()))
        strs.push_back(str);
    std::cout << strs.size() << '\n';
    for (const std::string& s : strs) {
        std::cout << s << '\n';
    }
}
