#include <iostream>
#include <vector>
#include <set>

const int N = (int) (2e5 + 10);

struct Segment {
    int index, length;
    Segment(int i, int l) : index{ i }, length{ l } {}
    bool operator<(const Segment& other) const {
        return index < other.index;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, arr[N];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::set<Segment> segments;
    std::vector<Segment> even;
    bool parity = arr[0] % 2;
    int lastIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 != parity) {
            segments.emplace(Segment(i, i - lastIndex));
            lastIndex = i;
            parity = !parity;
        }
    }
    segments.emplace(Segment(n, n - lastIndex));
    for (Segment s : segments) {
        if (s.length % 2 == 0) {
            even.emplace_back(s);
        }
    }
    while (!even.empty() && segments.size() > 1) {
        Segment cur = even.back();
        even.pop_back();
        auto first = segments.find(cur);
        auto last = segments.find(cur);
        if (first != segments.end()) {
            if (first != segments.begin()) {
                --first;
                cur.length += first->length;
            }
            if (++last != segments.end()) {
                cur.length += last->length;
                ++last;
            }
            segments.erase(first, last);
            segments.emplace(cur);
            if (cur.length % 2 == 0) {
                even.emplace_back(cur);
            }
        }
    }
    std::cout << (segments.size() == 1 ? "YES" : "NO") << '\n';
    return 0;
}
