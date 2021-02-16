#include <iostream>
#include <vector>

const int N = 1e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);

    int n, arr[N];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<std::vector<int>> stacks(N);
    int firstStack = 0, washed = 0, res = n;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < washed) {
            res = i;
            break;
        }
        int curStack = firstStack;
        while (!stacks[curStack].empty() && stacks[curStack][0] < arr[i]) {
            ++curStack;
        }
        int curSize = stacks[curStack].size();
        if (!stacks[curStack].empty() && stacks[curStack][curSize - 1] < arr[i]) {
            firstStack = curStack;
            for (int j = curSize - 1; j >= 0; --j) {
                if (stacks[curStack][j] < arr[i]) {
                    washed = stacks[curStack][j];
                    stacks[curStack].pop_back();
                }
            }
        }
        stacks[curStack].push_back(arr[i]);
    }
    std::cout << res << '\n';
    return 0;
}
