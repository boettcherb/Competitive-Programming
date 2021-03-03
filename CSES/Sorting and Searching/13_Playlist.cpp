#include <iostream>
#include <set>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, arr[N];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::set<int> set;
    int first = 0, curRes = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (set.find(arr[i]) == set.end()) {
            set.emplace(arr[i]);
            ++curRes;
        } else {
            res = std::max(res, curRes);
            while (arr[first++] != arr[i]) {
                set.erase(arr[first - 1]);
                --curRes;
            }
        }
    }
    std::cout << std::max(res, curRes) << '\n';
    return 0;
}
