#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
#endif

    int n, groups = 0;
    std::string A, B;
    std::cin >> n >> A >> B;
    for (int i = 0; i < n; ++i) {
        groups += A[i] != B[i] && (i == 0 || A[i - 1] == B[i - 1]);
    }
    std::cout << groups << '\n';
}
