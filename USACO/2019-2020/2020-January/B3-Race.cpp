#include <iostream>

long long sumN(long long n) {
    return n * (n + 1) / 2;
}

// If Bessie reaches top speed s in a race, can that race be valid? If so,
// how many seconds will the race take? Return -1 if not valid.
long long raceSeconds(long long s, long long k, long long x) {
    if (x > s) x = s;
    long long pos = sumN(s) + sumN(s - 1) - sumN(x - 1);
    long long secs = s + (s - 1) - (x - 1);
    if (pos >= k + x) return -1;
    if (pos >= k) return secs;
    long long secsAtTopSpeed = (k - pos) / s + ((k - pos) % s != 0);
    return secs + secsAtTopSpeed;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
#ifndef DB_LOCAL
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
#endif

    int k, n, x;
    std::cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (raceSeconds(mid, k, x) == -1) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        std::cout << raceSeconds(r, k, x) << '\n';
    }
}
