#include <iostream>
#include <string>
#include <set>

std::set<std::string> set;

void createStrings(std::string str, int len) {
    if (len == 1) {
        set.emplace(str);
    } else {
        int pos = str.length() - len;
        createStrings(str, len - 1);
        for (int i = 1; i < len; ++i) {
            std::swap(str[pos], str[pos + i]);
            createStrings(str, len - 1);
            std::swap(str[pos], str[pos + i]);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int letters[26] = { 0 };
    for (int i = 0; i < (int) str.length(); ++i) {
        ++letters[str[i] - 'a'];
    }
    int curLetter = 0;
    for (int i = 0; i < (int) str.length(); ++i) {
        while (!letters[curLetter]) {
            ++curLetter;
        }
        str[i] = curLetter + 'a';
        --letters[curLetter];
    }
    createStrings(str, str.length());
    std::cout << set.size() << '\n';
    for (const std::string& string : set) {
        std::cout << string << '\n';
    }
    return 0;
}
