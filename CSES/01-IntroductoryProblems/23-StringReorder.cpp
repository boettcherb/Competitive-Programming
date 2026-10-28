#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;
    int n = (int) str.length();
    std::vector<int> counts(26);
    for (int i = 0; i < n; ++i) {
        ++counts[str[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i) {
        int c = counts[i];
        if ((n % 2 == 0 && c > n / 2) || (n % 2 == 1 && c > n / 2 + 1)) {
            std::cout << -1 << '\n';
            return 0;
        }
    }
    char last = 0;
    for (int i = 0; i < n; ++i) {
        char first = 0, needed = 0;
        for (int j = 0; j < 26; ++j) {
            if (first == 0 && last != j + 'A' && counts[j] > 0)
                first = j + 'A';
            if (counts[j] > (n - i) / 2)
                needed = j + 'A';
        }
        if (needed) {
            --counts[needed - 'A'];
            str[i] = last = needed;
        } else {
            --counts[first - 'A'];
            str[i] = last = first;
        }
    }
    std::cout << str << '\n';
}
