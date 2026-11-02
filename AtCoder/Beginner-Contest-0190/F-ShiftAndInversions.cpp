#include <iostream>
#include <vector>

class FenwickTree {
private:
    int n;
    std::vector<int> tree;

public:
    explicit FenwickTree(int _n) : n(_n), tree(_n + 1, 0) {}

    void add(int index, int delta) {
        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int prefixSum(int index) const {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }

    int rangeSum(int l, int r) const {
        return l > r ? 0 : prefixSum(r) - prefixSum(l - 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i];
        ++arr[i];
    }
    FenwickTree ft(n);
    long long invNumber = 0;
    for (int i = 1; i <= n; ++i) {
        invNumber += ft.rangeSum(arr[i] + 1, n);
        ft.add(arr[i], 1);
    }
    std::cout << invNumber << '\n';
    for (int i = 1; i < n; ++i) {
        invNumber += n - arr[i] - arr[i] + 1;
        std::cout << invNumber << '\n';
    }
}
