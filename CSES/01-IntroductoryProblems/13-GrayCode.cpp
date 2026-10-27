#include <iostream>
#include <string>
#include <set>

void flipBit(std::string& str, int bitIndex) {
    str[bitIndex] = str[bitIndex] == '0' ? '1' : '0';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string cur(n, '0');
    std::set<std::string> seen;
    for (int i = 0; i < (1 << n); ++i) {
        std::cout << cur << '\n';
        seen.insert(cur);
        for (int j = n - 1; j >= 0; --j) {
            flipBit(cur, j);
            if (seen.find(cur) != seen.end())
                flipBit(cur, j);
            else break;
        }
    }
}
