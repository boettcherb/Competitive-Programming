#include <iostream>
#include <string>

std::string path;
bool used[9][9];

bool valid(int i, int j) {
    if (used[i][j]) return false;
    bool U = used[i - 1][j];
    bool D = used[i + 1][j];
    bool L = used[i][j - 1];
    bool R = used[i][j + 1];
    return !(U && D && !L && !R) && !(!U && !D && L && R);
}

int rec(int i, int j, int len) {
    if (i == 7 && j == 1) return len == 48;
    if (!valid(i, j)) return 0;
    int res = 0;
    used[i][j] = true;
    switch (path[len]) {
        case 'U': res += rec(i - 1, j, len + 1); break;
        case 'D': res += rec(i + 1, j, len + 1); break;
        case 'L': res += rec(i, j - 1, len + 1); break;
        case 'R': res += rec(i, j + 1, len + 1); break;
        case '?':
            res += rec(i - 1, j, len + 1);
            res += rec(i + 1, j, len + 1);
            res += rec(i, j - 1, len + 1);
            res += rec(i, j + 1, len + 1);
    }
    used[i][j] = false;
    return res;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> path;
    for (int i = 0; i < 9; ++i) {
        used[i][0] = used[0][i] = used[i][8] = used[8][i] = true;
    }
    std::cout << rec(1, 1, 0) << '\n';
}
