#include <iostream>
#include <string>

bool isLargest(const std::string& str, int pos) {
    for (int i = 0; i < str.length(); ++i) {
        if (i != pos && str[i] >= str[pos]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::string cur, max;
    for (int i = 0; i < n; ++i) {
        cur += 'a';
        max += (char) ('a' + i);
    }
    --n;
    std::cout << cur << '\n';
    while (cur < max) {
        if (!isLargest(cur, n)) {
            ++cur[n];
        } else {
            int pos = n;
            do {
                cur[pos--] = 'a';
            } while (isLargest(cur, pos));
            ++cur[pos];
        }
        std::cout << cur << '\n';
    }
    return 0;
}
