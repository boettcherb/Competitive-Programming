#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    long long votesT, votesA;
    std::cin >> votesT >> votesA;
    for (int i = 1; i < n; ++i) {
        long long t, a;
        std::cin >> t >> a;
        double prevRatio = (double) votesT / (double) votesA;
        double curRatio = (double) t / (double) a;
        if (curRatio < prevRatio) {
            if (votesT % t != 0) {
                votesT = (votesT / t + 1) * t;
            }
            votesA = votesT / t * a;
        } else {
            if (votesA % a != 0) {
                votesA = (votesA / a + 1) * a;
            }
            votesT = votesA / a * t;
        }
    }
    std::cout << votesT + votesA << '\n';
    return 0;
}
