#include <iostream>
#include <string>
#include <map>

const int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int n;
        std::string str;
        std::cin >> n >> str;
        std::map<std::pair<int, int>, int> map; // position, index
        int left = -1, right = -1, minCut = INF;
        int x = 0, y = 0;
        map[std::pair<int, int>(x, y)] = 0;
        for (int i = 1; i <= n; ++i) {
            if (str[i - 1] == 'L') --x;
            if (str[i - 1] == 'R') ++x;
            if (str[i - 1] == 'U') --y;
            if (str[i - 1] == 'D') ++y;
            std::pair<int, int> curPos(x, y);
            if (map.count(curPos)) {
                int curCut = i - map[curPos];
                if (curCut < minCut) {
                    minCut = curCut;
                    left = map[curPos] + 1;
                    right = i;
                }
            }
            map[curPos] = i;
        }
        if (left == -1 && right == -1) {
            std::cout << -1 << '\n';
        } else {
            std::cout << left << ' ' << right << '\n';
        }
    }
    return 0;
}
