#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    int curHouse = 1;
    long long res = 0;
    for (int i = 0; i < m; ++i) {
        int house;
        std::cin >> house;
        if (house >= curHouse) {
            res += house - curHouse;
        } else {
            res += n - curHouse + house;
        }
        curHouse = house;
    }
    std::cout << res << '\n';
    return 0;
}
