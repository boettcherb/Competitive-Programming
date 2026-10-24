#include <iostream>
#include <vector>
#include <string>

const int N = 101;
std::vector<int> cnt1(N), cnt2(N), cnt3(N);

int solve2(const std::string& num) {
    int L = (int) num.length();
    if (L < 2) return 0;
    int res = cnt2[L - 1] + (num[0] - '0' - 1) * cnt1[L - 1];
    int index = 1;
    while (index < L && num[index] == '0')
        ++index;
    if (index < L)
        res += num[index] - '0' + cnt1[L - index - 1];
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i < N; ++i) cnt1[i] = 9 * i;
    for (int i = 2; i < N; ++i) cnt2[i] = 9 * cnt1[i - 1] + cnt2[i - 1];
    for (int i = 3; i < N; ++i) cnt3[i] = 9 * cnt2[i - 1] + cnt3[i - 1];
    std::string num;
    int k, res;
    std::cin >> num >> k;
    int L = (int) num.length();
    if (k > L) {
        res = 0;
    } else if (k == 1) {
        res = cnt1[L - 1] + (num[0] - '0');
    } else if (k == 2) {
        res = solve2(num);
    } else if (k == 3) {
        res = cnt3[L - 1] + (num[0] - '0' - 1) * cnt2[L - 1];
        for (int i = 1; i < L; ++i) {
            if (num[i] != '0') {
                res += solve2(num.substr(i));
                break;
            }
        }
    }
    std::cout << res << '\n';
}
