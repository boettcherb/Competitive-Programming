#include <iostream>
#include <string>

const int N = 105;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n, min[N], max[N];
    std::string type[N];
    int firstNone = -1, lastNone;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> type[i] >> min[i] >> max[i];
        if (type[i] == "none") {
            lastNone = i;
            if (firstNone == -1) {
                firstNone = i;
            }
        }
    }
    int endMin = min[firstNone], endMax = max[firstNone];
    for (int i = firstNone + 1; i < n; ++i) {
        if (type[i] == "on") {
            endMin += min[i];
            endMax += max[i];
        } else if (type[i] == "off") {
            endMin -= max[i];
            endMax -= min[i];
        } else {
            endMin = std::max(endMin, min[i]);
            endMax = std::min(endMax, max[i]);
        }
        endMin = std::max(0, endMin);
    }
    int startMin = min[lastNone], startMax = max[lastNone];
    for (int i = lastNone - 1; i >= 0; --i) {
        if (type[i] == "on") {
            startMin -= max[i];
            startMax -= min[i];
        } else if (type[i] == "off") {
            startMin += min[i];
            startMax += max[i];
        } else {
            startMin = std::max(startMin, min[i]);
            startMax = std::min(startMax, max[i]);
        }
        startMin = std::max(0, startMin);
    }
    std::cout << startMin << ' ' << startMax << '\n';
    std::cout << endMin << ' ' << endMax << '\n';
    return 0;
}