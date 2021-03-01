#include <iostream>

const int N = 9;
bool grid[N][N];
std::string moves;

bool split(int I, int J) {
    if (grid[I + 1][J] && grid[I - 1][J])
        return !grid[I][J + 1] && !grid[I][J - 1];
    if (grid[I][J + 1] && grid[I][J - 1])
        return !grid[I + 1][J] && !grid[I - 1][J];
    return false;
}

int rec(int I, int J, int move) {
    if (grid[I][J]) return 0;
    if (I == 7 && J == 1) return move == 48;
    grid[I][J] = true;
    if (split(I, J)) {
        grid[I][J] = false;
        return 0;
    }
    int res = 0;
    switch (moves[move]) {
        case 'U': res += rec(I - 1, J, move + 1); break;
        case 'D': res += rec(I + 1, J, move + 1); break;
        case 'R': res += rec(I, J + 1, move + 1); break;
        case 'L': res += rec(I, J - 1, move + 1); break;
        case '?': 
            res += rec(I - 1, J, move + 1);
            res += rec(I + 1, J, move + 1);
            res += rec(I, J + 1, move + 1);
            res += rec(I, J - 1, move + 1);
    }
    grid[I][J] = false;
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = !i || !j || i == N - 1 || j == N - 1;
        }
    }
    std::cin >> moves;
    std::cout << rec(1, 1, 0) << '\n';
    return 0;
}
