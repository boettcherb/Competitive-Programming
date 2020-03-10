#include <iostream>
#include <vector>

const int N = 31;
const long long LIM = (long long) (1e16);

bool permutation(long long sum, long long goal[N], int n, int k) {
    std::vector<long long> allPowers;
    long long curK = 1;
    while (curK <= LIM) {
        allPowers.push_back(curK);
        curK *= k;
    }
    std::vector<long long> powersUsed;
    for (int i = (int) allPowers.size() - 1; i >= 0; --i) {
        if (sum >= allPowers[i]) {
            powersUsed.push_back(allPowers[i]);
            sum -= allPowers[i];
        }
    }
    if (sum != 0) {
        return false;
    }
    for (long long val : powersUsed) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (goal[j] >= val) {
                found = true;
                goal[j] -= val;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, k;
        std::cin >> n >> k;
        long long goal[N], sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> goal[i];
            sum += goal[i];
        }
        std::cout << (permutation(sum, goal, n, k) ? "YES" : "NO") << '\n';
    }
    return 0;
}
