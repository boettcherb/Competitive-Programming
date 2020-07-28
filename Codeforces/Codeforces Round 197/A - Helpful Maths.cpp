#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;
    int nums[3] = { 0 };
    for (int i = 0; i < str.length(); i += 2) {
        ++nums[str[i] - '1'];
    }
    int index = 0;
    for (int i = 0; i < 3; ++i) {
        while (nums[i]--) {
            str[index] = i + '1';
            index += 2;
        }
    }
    std::cout << str << '\n';
    return 0;
}
