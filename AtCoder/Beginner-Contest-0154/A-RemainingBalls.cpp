#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t, u;
    int a, b;
    std::cin >> s >> t >> a >> b >> u;
    if (u == s) --a;
    if (u == t) --b;
    std::cout << a << ' ' << b << '\n';
}
