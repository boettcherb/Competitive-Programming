#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::set<int> used;
    used.insert(arr[0]);
    int p1 = 0, p2 = 1, res = 1;
    while (p2 < n) {
        if (used.count(arr[p2])) {
            while (arr[p1] != arr[p2]) 
                used.erase(arr[p1++]);
            ++p1;
            ++p2;
        } else {
            used.insert(arr[p2++]);
            res = std::max(res, (int) used.size());
        }
    }
    std::cout << res << '\n';
}
