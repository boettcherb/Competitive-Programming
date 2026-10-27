#include <iostream>
#include <string>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;
    int n = (int) str.length();
    std::map<char, int> counts;
    for (int i = 0; i < n; ++i) {
        ++counts[str[i]];
    }
    int index = 0, oddCounts = 0;
    std::string res(n, '-');
    for (auto [c, count] : counts) {
        for (int i = 0; i < count / 2; ++i) {
            res[index] = res[n - 1 - index] = c;
            ++index;
        }
        if (count % 2 == 1) {
            res[n / 2] = c;
            ++oddCounts;
        }
    }
    std::cout << (oddCounts > 1 ? "NO SOLUTION" : res) << '\n';
}
