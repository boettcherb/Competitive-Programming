#include <iostream>
#include <string>
#include <vector>

const int N = 1010;
int res[N], scales[2] = { 0, 0 };
std::vector<int> weights;

bool recur(int cur, int last, int m) {
    if (cur == m) {
        return true;
    }
    int scale = cur % 2;
    for (int weight : weights) {
        if (weight != last && scales[scale] + weight > scales[scale ^ 1]) {
            res[cur] = weight;
            scales[scale] += weight;
            if (recur(cur + 1, weight, m)) {
                return true;
            }
            scales[scale] -= weight;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    int m;
    std::cin >> str >> m;
    for (int i = 0; i < 10; ++i) {
        if (str[i] == '1') {
            weights.push_back(i + 1);
        }
    }
    if (recur(0, -1, m)) {
        std::cout << "YES" << '\n';
        for (int i = 0; i < m; ++i) {
            std::cout << res[i] << ' ';
        }
        std::cout << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
    return 0;
}
