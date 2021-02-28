#include <iostream>
#include <string>

const int N = 8;
int grid[N][N];

bool valid(int qi, int qj) {
    for (int j = 1; j <= qj; ++j) {
        if (grid[qi][j - 1] == 1) {
            return false;
        }
        if (qi - j >= 0 && grid[qi - j][qj - j] == 1) {
            return false;
        }
        if (qi + j < N && grid[qi + j][qj - j] == 1) {
            return false;
        }
    }
    return true;
}

int rec(int line) {
    if (line >= N) {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (grid[i][line] != -1) {
            grid[i][line] = 1;
            if (valid(i, line)) {
                res += rec(line + 1);
            }
            grid[i][line] = 0;
        }
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i < N; ++i) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < N; ++j) {
            grid[i][j] = line[j] == '.' ? 0 : -1;
        }
    }
    std::cout << rec(0) << '\n';
    return 0;
}
