#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    bool print = false;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (print) {
            std::cout << cur << ' ';
        } else {
            q.push(cur);
        }
        print = !print;
    }
    std::cout << '\n';
    return 0;
}
