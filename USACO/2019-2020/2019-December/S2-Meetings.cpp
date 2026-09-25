#include <iostream>
#include <vector>
#include <algorithm>

struct Cow {
    int pos, dir, weight;
    int exit_time = -1;
    Cow(int p, int d, int w) : pos{p}, dir{d}, weight{w} {}
    bool operator<(const Cow& other) {
        return pos < other.pos;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
#endif

    int n, L, total_weight = 0;
    std::cin >> n >> L;
    std::vector<Cow> cows, left, right;
    for (int i = 0; i < n; ++i) {
        int w, x, d;
        std::cin >> w >> x >> d;
        Cow c = Cow(x, d, w);
        cows.push_back(c);
        (d == 1 ? right : left).push_back(c);
        total_weight += w;
    }
    int sizeL = (int) left.size(), sizeR = (int) right.size();
    std::sort(cows.begin(), cows.end());
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    for (int i = 0; i < sizeL; ++i) {
        cows[i].exit_time = left[i].pos;
    }
    for (int i = 0; i < sizeR; ++i) {
        cows[sizeL + i].exit_time = L - right[i].pos;
    }
    std::sort(cows.begin(), cows.end(), [](const Cow& c1, const Cow& c2) {
        return c1.exit_time < c2.exit_time;
    });
    int threshold = total_weight / 2 + (total_weight % 2);
    int weight_exited = 0;
    int T = -1;
    for (const Cow& c : cows) {
        weight_exited += c.weight;
        if (weight_exited >= threshold) {
            T = c.exit_time;
            break;
        }
    }
    int pl = 0, pr = 0, meetings = 0;
    for (int i = 0; i < sizeR; ++i) {
        while (pl < sizeL && left[pl].pos < right[i].pos) ++pl;
        while (pr < sizeL && left[pr].pos <= right[i].pos + 2 * T) ++pr;
        meetings += pr - pl;
    }
    std::cout << meetings << '\n';
}
