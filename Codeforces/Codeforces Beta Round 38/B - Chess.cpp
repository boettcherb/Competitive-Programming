#include <iostream>
#include <string>

const int KNIGHT_X[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
const int KNIGHT_Y[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::string rookPos, knightPos;
    std::cin >> rookPos >> knightPos;
    int rookX = rookPos[0] - 'a', rookY = rookPos[1] - '1';
    int knightX = knightPos[0] - 'a', knightY = knightPos[1] - '1';
    int board[12][12] = { 0 };
    for (int i = 0; i < 8; ++i) {
        board[rookX + 2 + KNIGHT_X[i]][rookY + 2 + KNIGHT_Y[i]] = 1;
        board[knightX + 2 + KNIGHT_X[i]][knightY + 2 + KNIGHT_Y[i]] = 1;
    }
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i != rookPos[0] - 'a' && j != rookPos[1] - '1') {
                res += !board[i + 2][j + 2] && (i != knightX || j != knightY);
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}