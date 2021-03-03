#include <iostream>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, arr[N], pos[N], res = 1;
    std::cin >> n >> m;
    bool seen[N] = { false };
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        res += seen[arr[i] + 1];
        seen[arr[i]] = true;
        pos[arr[i]] = i;
    }    
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        if (--b < --a) std::swap(a, b);
        int nums[4] = { arr[a] - 1, arr[a] + 1, arr[b] - 1, arr[b] + 1 };
        int change[4] = { -1, 1, 1, -1 };
        for (int i = 0; i < 4; ++i) {
            if (nums[i] > 0 && nums[i] <= n) {
                if (pos[nums[i]] > a && pos[nums[i]] < b) {
                    res += change[i];
                }
            }
        }
        if (std::abs(arr[a] - arr[b]) == 1) {
            res += arr[a] < arr[b] ? 1 : -1;
        }
        std::swap(arr[a], arr[b]);
        std::swap(pos[arr[a]], pos[arr[b]]);
        std::cout << res << '\n';
    }
}
