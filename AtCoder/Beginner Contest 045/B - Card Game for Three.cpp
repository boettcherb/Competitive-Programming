#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string A, B, C;
    std::cin >> A >> B >> C;
    int indexA = 0, indexB = 0, indexC = 0;
    int turn = 0; // 0 = A, 1 = B, 2 = C
    while (true) {
        if (turn == 0) {
            if (indexA >= A.length()) {
                break;
            }
            turn = A[indexA++] - 'a';
        } else if (turn == 1) {
            if (indexB >= B.length()) {
                break;
            }
            turn = B[indexB++] - 'a';
        } else {
            if (indexC >= C.length()) {
                break;
            }
            turn = C[indexC++] - 'a';
        }
    }
    std::cout << (turn == 0 ? 'A' : turn == 1 ? 'B' : 'C') << '\n';
    return 0;
}
