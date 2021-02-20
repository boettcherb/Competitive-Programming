#include <iostream>
#include <algorithm>

const int N = 5e4 + 10;

struct Cow {
    int pos;
    short weight;
    short dir;

    bool operator<(const Cow& other) const {
        return pos < other.pos;
    }
} cows[N];

float time(int cow1, int cow2) {
    return (cows[cow1].pos - cows[cow2].pos) / 2.0f;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);

    int n, L, totalWeight = 0;
    std::cin >> n >> L;
    for (int i = 0; i < n; ++i) {
        std::cin >> cows[i].weight >> cows[i].pos >> cows[i].dir;
        totalWeight += cows[i].weight;
    }
    std::sort(cows, cows + n);
    int prefixLeft[N] = { 0 }, prefixRight[N] = { 0 };
    int numLeftCows = 0, leftCows[N];
    int numRightCows = 0, rightCows[N];
    for (int i = 0; i < n; ++i) {
        if (cows[i].dir == -1) {
            leftCows[numLeftCows++] = i;
            prefixLeft[i] = 1;
        } else {
            rightCows[numRightCows++] = i;
            prefixRight[i] = 1;
        }
    }
    if (numLeftCows == 0 || numRightCows == 0) {
        std::cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        prefixLeft[i] += prefixLeft[i - 1];
        prefixRight[i] += prefixRight[i - 1];
    }
    int newWeights[N] = { 0 };
    for (int i = 0; i < n; ++i) {
        int ltor = i ? prefixRight[i - 1] : 0;
        int rtol = prefixLeft[n - 1] - prefixLeft[i];
        if (cows[i].dir == -1) {
            if (ltor > rtol) {
                int index = ltor - rtol - 1;
                newWeights[rightCows[index]] = cows[i].weight;
            } else {
                int index = prefixLeft[i] + ltor - 1;
                newWeights[leftCows[index]] = cows[i].weight;
            }
        }
        else {
            if (rtol > ltor) {
                int index = prefixLeft[i] + ltor;
                newWeights[leftCows[index]] = cows[i].weight;
            } else {
                int index = ltor - rtol;
                newWeights[rightCows[index]] = cows[i].weight;
            }
        }
    }
    std::pair<int, int> endings[N];
    for (int i = 0; i < n; ++i) {
        endings[i].second = i;
        endings[i].first = cows[i].dir == 1 ? L - cows[i].pos : cows[i].pos;
    }
    std::sort(endings, endings + n);
    int endTime = 0, weightStopped = 0;
    for (int i = 0; i < n; ++i) {
        weightStopped += newWeights[endings[i].second];
        if (weightStopped * 2 >= totalWeight) {
            endTime = endings[i].first;
            break;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (cows[i].dir == 1 && prefixLeft[n - 1] - prefixLeft[i] > 0) {
            if (time(leftCows[prefixLeft[i]], i) > (float) endTime) {
                continue;
            }
            int l = prefixLeft[i], r = numLeftCows - 1;
            while (l + 2 < r) {
                int mid = (l + r) / 2;
                if (time(leftCows[mid], i) <= (float) endTime) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            while (l <= r && time(leftCows[l], i) <= (float) endTime) {
                ++l;
            }
            res += l - prefixLeft[i];
        }
    }
    std::cout << res << '\n';
    return 0;
}