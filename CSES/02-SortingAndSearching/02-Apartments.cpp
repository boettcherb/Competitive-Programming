#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> applicant(n), apartment(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> applicant[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> apartment[i];
    }
    std::sort(applicant.begin(), applicant.end());
    std::sort(apartment.begin(), apartment.end());
    int p1 = 0, p2 = 0, res = 0;
    while (p1 < n && p2 < m) {
        if (std::abs(applicant[p1] - apartment[p2]) <= k) {
            ++res;
            ++p1;
            ++p2;
        } else if (applicant[p1] < apartment[p2]) {
            ++p1;
        } else {
            ++p2;
        }
    }
    std::cout << res << '\n';
}
