#include <iostream>

void mixMilk(int& a, int& b, int b_cap) {
    int moved = std::min(a, b_cap - b);
    a -= moved;
    b += moved;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
#endif

    int c1, m1, c2, m2, c3, m3;
    std::cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    for (int i = 0; i < 33; ++i) {
        mixMilk(m1, m2, c2);
        mixMilk(m2, m3, c3);
        mixMilk(m3, m1, c1);
    }
    mixMilk(m1, m2, c2);
    std::cout << m1 << '\n' << m2 << '\n' << m3 << '\n';
}
