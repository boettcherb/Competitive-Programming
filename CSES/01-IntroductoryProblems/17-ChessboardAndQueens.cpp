#include <iostream>
#include <vector>

std::vector<std::string> board(8);

bool canPlace(int row, int col) {
    for (int i = 1; i <= row; ++i) {
        if (board[row - i][col] == 'Q') return false;
        if (col + i < 8 && board[row - i][col + i] == 'Q') return false;
        if (col - i >= 0 && board[row - i][col - i] == 'Q') return false;
    }
    return true;
}

int rec(int row) {
    if (row >= 8)
        return 1;
    int res = 0;
    for (int col = 0; col < 8; ++col) {
        if (board[row][col] == '*') continue;
        if (canPlace(row, col)) {
            board[row][col] = 'Q';
            res += rec(row + 1);
            board[row][col] = '.';
        }
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < 8; ++i) {
        std::cin >> board[i];
    }
    std::cout << rec(0) << '\n';
}
