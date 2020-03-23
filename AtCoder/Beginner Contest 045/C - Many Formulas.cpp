#include <iostream>
#include <string>

const int N = 10;
std::string str;

long long recur(int index, bool plus[N]) {
    if (index >= str.length() - 1) {
        long long sum = 0;
        long long curNum = 0;
        for (int i = 0; i < str.length() - 1; ++i) {
            curNum += str[i] - '0';
            if (plus[i]) {
                sum += curNum;
                curNum = 0;
            } else {
                curNum *= 10;
            }
        }
        return sum + curNum + str[str.length() - 1] - '0';
    }
    plus[index] = true;
    long long res = recur(index + 1, plus);
    plus[index] = false;
    return res + recur(index + 1, plus);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> str;
    bool plus[N] = { false };
    std::cout << recur(0, plus) << '\n';
    return 0;
}
