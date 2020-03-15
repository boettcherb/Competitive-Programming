#include <iostream>
#include <string>

const int N = 26;

bool allEven(const int counts[N]) {
    for (int i = 0; i < N; ++i) {
        if (counts[i] % 2) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int counts[N] = { 0 };
    for (const char c : str) {
        ++counts[c - 'a'];
    }
    std::cout << (allEven(counts) ? "Yes" : "No") << '\n';
    return 0;
}
