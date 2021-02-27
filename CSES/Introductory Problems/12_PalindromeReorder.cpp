#include <iostream>
#include <string>

const int N = 1e6 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int letters[26] = { 0 };
    for (int i = 0; i < (int) str.length(); ++i) {
        ++letters[str[i] - 'A'];
    }
    int odd = -1;
    for (int i = 0; i < 26; ++i) {
        if (letters[i] % 2 == 1) {
            if (odd != -1 || str.length() % 2 == 0) {
                std::cout << "NO SOLUTION" << '\n';
                return 0;
            }
            odd = i;
        }
    }
    char res[N] = { '\0' };
    int letter = 0;
    for (int i = 0; i < (int) str.length() / 2; ++i) {
        while (letters[letter] < 2) {
            ++letter;
        }
        res[i] = res[str.length() - 1 - i] = 'A' + letter;
        letters[letter] -= 2;
    }
    if (odd != -1) {
        res[str.length() / 2] = 'A' + odd;
    }
    std::cout << res << '\n';
    return 0;
}